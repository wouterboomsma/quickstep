#include "quickstep/Selection.h"

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/qi_lit.hpp>
#include <boost/spirit/repository/include/qi_distinct.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/at_c.hpp>
#include <boost/bind.hpp>

#include "quickstep/Topology.h"
#include "prettyprint.hpp"

namespace quickstep {

/** \class Node
  *
  * \brief Base class for nodes in parser
  *
  * All nodes in the hierarchy have an eval member function that takes a
  * topology argument and returns a Selection */
struct Node {

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const {return Selection{topology};}

    /** Textual representation for node
     *  To support virtual calls on output operator */
    virtual std::ostream &output(std::ostream &o) const {return o;}

    /** Output operator
     *  overridden by derived classes */
    friend std::ostream &operator<<(std::ostream &o, const Node &node) {
        return node.output(o);
    }
};

/** \class NodeHolder
 *  \brief Helper class for constructing AnyNode
 *
 *  The class is constructed with one of the derived
 *  nodes, which is stored internally using a inner Base class.
 *  This means nodes can be passe by value while retaining
 *  their polymorphic properties.
 *
 *  */
struct NodeHolder {
    NodeHolder() = default;

    /** Construct new holder from templated node */
    template <typename NodeType>
    NodeHolder(NodeType node)
            : storage(new ConcreteStore<NodeType>{std::move(node)}) {}

    /** Support for implicit cast to node */
    operator Node&() const {
        return storage->get();
    }
private:
    /** Inner base class for supporting polymorphism internally */
    struct BaseStore {
        virtual ~BaseStore(){}
        virtual Node &get() = 0;
    };
    /** Inner derived class for supporting polymorphism internally */
    template <typename T>
    struct ConcreteStore: BaseStore {
        ConcreteStore(T v):
                wrapped(std::move(v)){}
        virtual Node &get() {
            return wrapped;
        }
    private:
        T wrapped;
    };
    std::shared_ptr<BaseStore> storage;
};

/** \class AnyNode
 *  \brief Provides value semantics while maintaining polymorphism internally */
struct AnyNode: Node {

    AnyNode() = default;

    /** Construct AnyNode from any node type */
    template <typename NodeType>
    AnyNode(NodeType node)
            : holder(std::move(node)) {

    }

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const override {
        return static_cast<Node&>(holder).eval(topology);
    }

private:
    NodeHolder holder;
};


/** \class OperatorVistor
 *  \ brief Visitor pattern for iterating over boost::variant operator types */
template<typename Operator>
class OperatorVisitor
        : public boost::static_visitor<bool> {
public:
    /** Create a new visitor */
    OperatorVisitor(const Operator &op,
                    const Topology::Atom &atom,
                    const std::string &token_value)
            : op(op), atom(atom), token_value(token_value) {}

    /** Call operator overloaded for integer fields */
    bool operator()(const std::function<int(const Topology::Atom&)> &function) const {
        return op(function(atom), std::stoi(token_value));
    }
    /** Call operator overloaded for double fields */
    bool operator()(const std::function<double(const Topology::Atom&)> &function) const {
        return op(function(atom), std::stod(token_value));
    }
    /** Call operator overloaded for string fields */
    bool operator()(const std::function<std::string(const Topology::Atom&)> &function) const {
        return op(function(atom), token_value);
    }
    /** Call operator overloaded for Element fields */
    bool operator()(const std::function<Element(const Topology::Atom&)> &function) const {
        return op(function(atom), Element::get_by_symbol(token_value));
    }
private:
    const Operator op;
    const Topology::Atom &atom;
    const std::string token_value;
};


/** Helper function for creating map with multiple keys for the same value */
template <typename FieldTypes>
std::map<std::string, FieldTypes> make_keyword_map(std::vector<std::pair<std::vector<std::string>, FieldTypes>> &&input) {
    std::map<std::string, FieldTypes> map;
    for (const std::pair<std::vector<std::string>, FieldTypes> &entry: input) {
        for (const std::string &key: entry.first) {
            map.insert({key, entry.second});
        }
    }
    return std::move(map);
};


/** \class Attribute
 *  \brief Grammar node for modeling atom attributes */
struct Attribute: public Node {

    // Different field types are encoded as a single type using boost::Variant
    typedef boost::variant<std::function<int        (const Topology::Atom&)>,
                           std::function<double     (const Topology::Atom&)>,
                           std::function<std::string(const Topology::Atom&)>,
                           std::function<Element    (const Topology::Atom&)>> FieldTypes;

    /** Map of all available attrbutes and associated retrieval functors */
    const static std::map<std::string, FieldTypes> fields;

    Attribute() = default;

    /** Create new attribute from field name */
    Attribute(std::string field_name)
            : field_name(std::move(field_name)) {}

    /** Apply comparison operator on attribute value
     *  @param op Comparison operator
     *  @atom atom on which comparison should be applied
     *  @atom token_value Operand value encoded in selection string */
    template<typename Operator>
    bool binary_op(const Operator &op,
                   const Topology::Atom &atom, const std::string &token_value) const {
        return boost::apply_visitor(OperatorVisitor<Operator>(op, atom, token_value), fields.at(field_name));
    };

private:
    std::string field_name;
};
const std::map<std::string, Attribute::FieldTypes> Attribute::fields = make_keyword_map<Attribute::FieldTypes>(
        {{{"resi","resid"}, std::function<int(const Topology::Atom&)>(
                [](const Topology::Atom &atom){return atom.residue.index;})},
         {{"resn"}, std::function<std::string(const Topology::Atom&)>(
                 [](const Topology::Atom &atom){return atom.residue.name;})},
         {{"type","element","symbol"}, std::function<Element(const Topology::Atom&)>(
                 [](const Topology::Atom &atom){return atom.element;})},
         {{"name"}, std::function<std::string(const Topology::Atom&)>(
                 [](const Topology::Atom &atom){return atom.name;})},
        });


/** \class BinaryOp
 *  \brief Grammar node for representing operation between two subexpressions */
struct BinaryOp: public Node {

    /** All registered keywords and associated functors */
    const static std::map<std::string, std::function<Selection(Selection,Selection)>> keywords;

    BinaryOp(){}

    /** Construct from two nodes and a string representing the operator */
    BinaryOp(const boost::fusion::vector3<AnyNode, std::string, AnyNode> &tokens)
            : operand1(boost::fusion::at_c<0>(tokens)),
              operator_str(boost::fusion::at_c<1>(tokens)),
              operand2(boost::fusion::at_c<2>(tokens)){}

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const {
        return keywords.at(operator_str)(operand1.eval(topology), operand2.eval(topology));
    }

    /** Textual representation for node
     *  To support virtual calls on output operator */
    virtual std::ostream &output(std::ostream &o) const {
        o << "BinaryOp("<<operator_str<<")";
        return o;
    }

private:
    AnyNode operand1;
    std::string operator_str;
    AnyNode operand2;
};
const std::map<std::string, std::function<Selection(Selection,Selection)>> BinaryOp::keywords = make_keyword_map<std::function<Selection(Selection,Selection)>>(
        {{{"and","&&"}, std::bit_and<Selection>()},
         {{"or", "||"}, std::bit_or<Selection>()}
        });


/** \class BinaryOp
 *  \brief Grammar node for representing operation on a subexpression */
struct UnaryOp: public Node {

    /** All registered keywords and associated functors */
    const static std::map<std::string, std::function<Selection(Selection)>> keywords;

    UnaryOp(){}

    /** Construct from a node and a string representing the operator */
    UnaryOp(const boost::fusion::vector2<std::string, AnyNode> &tokens)
            : operator_str(boost::fusion::at_c<0>(tokens)),
              operand(boost::fusion::at_c<1>(tokens)){}

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const {
        return keywords.at(operator_str)(operand.eval(topology));
    }

    /** Textual representation for node
     *  To support virtual calls on output operator */
    virtual std::ostream &output(std::ostream &o) const {
        o << "UnaryOp("<<operator_str<<")";
        return o;
    }

private:
    std::string operator_str;
    AnyNode operand;
};
const std::map<std::string, std::function<Selection(Selection)>> UnaryOp::keywords = make_keyword_map<std::function<Selection(Selection)>>(
        {{{"not","!"}, std::bit_not<Selection>()}
        });



/** \class EqualityCondition
 *  \brief Grammar node for representing the equality between an attribute and a value */
struct EqualityCondition : public Node {

    EqualityCondition(){}

    /** Construct from an Attribute and a string representing the value */
    EqualityCondition(const boost::fusion::vector2<Attribute, std::string> &tokens)
            : attribute(boost::fusion::at_c<0>(tokens)),
              value(boost::fusion::at_c<1>(tokens)){}

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const {
        Eigen::Array<bool, Eigen::Dynamic, 1> active_atoms = Eigen::Array<bool, Eigen::Dynamic, 1>::Zero(topology.atoms.size());
        for (const auto &atom: topology.atoms) {
            if (attribute.binary_op(std::equal_to<void>(), atom, value))
                active_atoms[atom.index] = true;
        }
        return Selection(topology, std::move(active_atoms));
    }

    /** Textual representation for node
     *  To support virtual calls on output operator */
    virtual std::ostream &output(std::ostream &o) const {
        o << "EqualityConditionNode("<<attribute << "," << value <<")";
        return o;
    }

private:
    Attribute attribute;
    std::string value;
};


/** \class RangeCondition
 *  \brief Grammar node for representing an attribute having a value between a lower and higher bound */
struct RangeCondition: public Node {

    RangeCondition(){}

    /** Construct from an Attribute and a strings representing lower and upper bounds */
    RangeCondition(const boost::fusion::vector3<Attribute, std::string, std::string> &tokens)
            : attribute(boost::fusion::at_c<0>(tokens)),
              start(boost::fusion::at_c<1>(tokens)),
              end(boost::fusion::at_c<2>(tokens)){}

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const {
        Eigen::Array<bool, Eigen::Dynamic, 1> active_atoms = Eigen::Array<bool, Eigen::Dynamic, 1>::Zero(topology.atoms.size());
        for (const auto &atom: topology.atoms) {
            if (attribute.binary_op(std::greater_equal<void>(), atom, start) &&
                attribute.binary_op(std::less_equal<void>(),    atom, end))
                active_atoms[atom.index] = true;
        }
        return Selection(topology, std::move(active_atoms));
    }

    /** Textual representation for node
     *  To support virtual calls on output operator */
    virtual std::ostream &output(std::ostream &o) const {
        o << "RangeConditionNode("<<attribute << "," << start << "," << end <<")";
        return o;
    }

private:
    Attribute attribute;
    std::string start, end;
};


/** \class Bonded
 *  \brief Grammar node for representing an attribute in a stretch of bonded atoms */
struct Bonded: public Node {

    Bonded(){}

    /** Construct from an Attribute and a vector of strings representing values along the bonded chain */
    Bonded(const boost::fusion::vector3<Attribute, std::string, std::vector<std::string>> &tokens)
            : attribute(boost::fusion::at_c<0>(tokens)),
              values({boost::fusion::at_c<1>(tokens)}) {
        values.insert(values.end(), boost::fusion::at_c<2>(tokens).begin(), boost::fusion::at_c<2>(tokens).end());
    }

    /** Create selection based on current topology
     *  @param topology Current topology
     *  \returns selection */
    virtual Selection eval(Topology &topology) const {
        std::vector<std::set<std::vector<unsigned int> > > active_bonds(values.size());
        for (const auto &atom: topology.atoms) {
            if (attribute.binary_op(std::equal_to<void>(), atom, values[0])) {
                std::vector<unsigned int> new_bond_vector = {atom.index};
                active_bonds[0].insert(new_bond_vector);
                recursive_atom_traversal(topology, new_bond_vector, active_bonds);
            }
        }

        return Selection{topology, {}, active_bonds[values.size()-1]};
    }

    /** Textual representation for node
     *  To support virtual calls on output operator */
    virtual std::ostream &output(std::ostream &o) const {
        o << "Bonded("<<attribute << "," << values <<")";
        return o;
    }

private:
    /** Helper function for \ref eval() */
    void recursive_atom_traversal(Topology &topology, std::vector<unsigned int> &atom_indices,
                                  std::vector<std::set<std::vector<unsigned int> > > &active_bonds) const {

        if (atom_indices.size() == values.size())
            return;

        const auto &bonded_to = topology.get_bond_adjacency_list();
        for (int atom_index: bonded_to[atom_indices.back()]) {

            // Skip if atom index is already included
            if (std::find(atom_indices.begin(), atom_indices.end()-1, atom_index) != (atom_indices.end()-1))
                continue;


            const Topology::Atom &atom = topology.atoms[atom_index];
            if (attribute.binary_op(std::equal_to<void>(), atom, values[atom_indices.size()])) {
                std::vector<unsigned int> new_bond_vector = atom_indices;
                new_bond_vector.push_back(atom.index);
                // Sort by minimum atom index order (to avoid duplicate entries with reverse order)
                if (!std::lexicographical_compare(new_bond_vector.begin(), new_bond_vector.end(),
                                                  new_bond_vector.rbegin(), new_bond_vector.rend()))
                    std::reverse(new_bond_vector.begin(), new_bond_vector.end());
                if (active_bonds[atom_indices.size()].count(new_bond_vector) == 0) {
                    active_bonds[atom_indices.size()].insert(new_bond_vector);
                    recursive_atom_traversal(topology, new_bond_vector, active_bonds);
                }
            }
        }
    }

private:
    Attribute attribute;
    std::vector<std::string> values;
};


/** \class Grammar
 *  \brief The main grammar */
template <typename Iterator>
struct Grammar: boost::spirit::qi::grammar<Iterator, AnyNode(), boost::spirit::ascii::space_type> {

    /** \class Rule. Inner class for increasing ease with which debug can be turned on for all rules */
    template <typename RuleType>
    struct Rule : public RuleType {

        Rule()
                : RuleType() {}

        Rule(const std::string name)
                : RuleType(name) {}

        template <typename Expr>
        Rule & operator=(Expr const& expr)
        {
            RuleType::operator=(expr);
            if (debug)
                boost::spirit::qi::debug(*this);
            return *this;
        }
        template <typename Expr>
        Rule & operator%=(Expr const& expr)
        {
            static_cast<RuleType&>(*this)%=expr;
            if (debug)
                boost::spirit::qi::debug(*this);
            return *this;
        }
        template <typename Expr>
        Rule & operator%=(Expr && expr)
        {
            static_cast<RuleType&>(*this) %= std::move(expr);
            if (debug)
                boost::spirit::qi::debug(*this);
            return *this;
        }
    private:
        static constexpr bool debug = false;
    };

    // Rule variable definition (these must be defined here rather than in the constructor)
    Rule<boost::spirit::qi::rule<Iterator, std::string(), boost::spirit::ascii::space_type>> number_int = {"number_int"};
    Rule<boost::spirit::qi::rule<Iterator, boost::spirit::ascii::space_type>> number_float = {"number_float"};
    Rule<boost::spirit::qi::rule<Iterator, std::string(), boost::spirit::ascii::space_type>> identifier = {"identifier"};
    Rule<boost::spirit::qi::rule<Iterator, std::string(), boost::spirit::ascii::space_type>> literal = {"literal"};
    Rule<boost::spirit::qi::rule<Iterator, Attribute(), boost::spirit::ascii::space_type>> attribute = {"attribute"};
//    DebugRule<boost::spirit::qi::rule<Iterator, std::string(), boost::spirit::ascii::space_type>> base_expression = {"base_expression"};
    Rule<boost::spirit::qi::rule<Iterator, EqualityCondition(), boost::spirit::ascii::space_type>> implicit_equality = {"implicit equality"};
    Rule<boost::spirit::qi::rule<Iterator, RangeCondition(), boost::spirit::ascii::space_type>> range_condition = {"range_condition"};
    Rule<boost::spirit::qi::rule<Iterator, Bonded(), boost::spirit::ascii::space_type>> bonded = {"bonded"};
    Rule<boost::spirit::qi::rule<Iterator, AnyNode(), boost::spirit::ascii::space_type>> expression = {"expression"};
    Rule<boost::spirit::qi::rule<Iterator, AnyNode(), boost::spirit::ascii::space_type>> logical_expression = {"logical_expression"};
    Rule<boost::spirit::qi::rule<Iterator, AnyNode(), boost::spirit::ascii::space_type>> or_op = {"or_op"};
    Rule<boost::spirit::qi::rule<Iterator, AnyNode(), boost::spirit::ascii::space_type>> and_op = {"and_op"};
    Rule<boost::spirit::qi::rule<Iterator, AnyNode(), boost::spirit::ascii::space_type>> not_op = {"not_op"};
    Rule<boost::spirit::qi::rule<Iterator, AnyNode(), boost::spirit::ascii::space_type>> start = {"start"};

    boost::spirit::qi::symbols<char,std::string> field_keywords;

    // Using the distinct technique directive produced a memory error - we therefore use the manual method below
    // auto keyword(std::string keyword_string) -> decltype(boost::spirit::repository::distinct(boost::spirit::qi::char_("a-zA-Z_0-9"))[keyword_string]) {
    //     return boost::spirit::repository::distinct(boost::spirit::qi::char_("a-zA-Z_0-9"))[keyword_string];
    // }

    ///** Helper function for constructing a keyword that is not a prefix of a label */
    //auto keyword(std::string keyword_string) -> decltype(boost::spirit::qi::lexeme[boost::spirit::qi::lit(keyword_string) >> !boost::spirit::qi::char_("a-zA-Z_0-9")]) {
    //    namespace qi = boost::spirit::qi;
    //    return qi::lexeme[boost::spirit::qi::lit(keyword_string) >> !qi::char_("a-zA-Z_0-9")];
    //}


    Grammar(): Grammar::base_type(start) {

        using boost::spirit::qi::lit;
        using namespace boost::spirit::qi::labels;
        namespace qi = boost::spirit::qi;
        namespace ascii = boost::spirit::ascii;
        namespace lambda = boost::lambda;
        namespace phx = boost::phoenix;

        // Import attribute field names as keywords.
        for (const auto &field: Attribute::fields)
           field_keywords.add(field.first, field.first);


        // The grammar

        number_int =
                +(ascii::digit) ;

        number_float =
                +(ascii::digit | '.') ;

        identifier =
                qi::lexeme[(ascii::alpha | '_') >> *( ascii::alnum | '_' )];

        literal =
                number_int | identifier ;

        attribute %=
                qi::as_string[field_keywords];

//        base_expression =
//                attribute | literal;

        implicit_equality =
                ( attribute >> -lit("==") >> literal ) [_val = _0];

        range_condition =
                (attribute >> literal >> qi::lexeme[boost::spirit::qi::lit("to") >> !qi::char_("a-zA-Z_0-9")] >> literal) [_val = _0];

        bonded = ( lit("bonded") >> attribute >> -lit("==") >> literal >> *(lit("-") >> literal) ) [_val = _0];

        expression =
                  range_condition | implicit_equality | bonded;

        // Precedence: not, and, or
        or_op = ( and_op >> (ascii::string("or") |
                             ascii::string("||")) >> and_op)   [_val = phx::construct<BinaryOp>(_0)]
                | and_op                                       [_val = qi::labels::_1] ;
        and_op = ( not_op >> (ascii::string("and") |
                              ascii::string("||")) >> not_op)  [_val = phx::construct<BinaryOp>(_0)]
                 | expression                                  [_val = qi::labels::_1] ;
        not_op = ( (ascii::string("not") |
                    ascii::string("!"))  > expression)         [_val = phx::construct<UnaryOp>(_0)]
                 | expression                                  [_val = qi::labels::_1] ;

        logical_expression = or_op.alias();

        start = logical_expression ;


        using boost::phoenix::construct;
        using boost::phoenix::val;
        qi::on_error<qi::fail>
                (
                        start
                        , std::cout
                          << val("Error! Expecting ")
                          << qi::_4                               // what failed?
                          << val(" here: \"")
                          << construct<std::string>(qi::_3, qi::_2)   // iterators to error-pos, end
                          << val("\"")
                          << std::endl
                );


    }
};

Selection Selection::parse(Topology &topology, const std::string &selection_string) {

    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    using qi::double_;
    using qi::phrase_parse;
    using ascii::space;

    Grammar<std::string::const_iterator> grammar;

    AnyNode result;
    bool r = qi::phrase_parse(selection_string.begin(),
                              selection_string.end(),
                              grammar,
                              space,
                              result);
    return result.eval(topology);

}

std::vector<std::reference_wrapper<Topology::Atom>> Selection::get_atoms() {
    std::vector<std::reference_wrapper<Topology::Atom>> atoms;
    atoms.reserve(active_atoms.size());
    std::cout << active_atoms.rows() << " " << active_atoms.cols() << " " << active_atoms.size() << "\n";
    for (int i=0; i<active_atoms.size(); ++i) {
        if (active_atoms[i])
            atoms.push_back(std::ref(topology.atoms[i]));
    }
    return std::move(atoms);
}

std::vector<std::vector<std::reference_wrapper<Topology::Atom>>> Selection::get_bonds() {
    std::vector<std::vector<std::reference_wrapper<Topology::Atom>>> bonds;
    bonds.reserve(active_bonds.size());
    for (const auto bond: active_bonds) {
        std::vector<std::reference_wrapper<Topology::Atom>> bond_atom_vector;
        bool include = true;
        for (int atom_index: bond) {
            if (active_atoms.size()>0 && !active_atoms[atom_index]) {
                include = false;
                break;
            }
            bond_atom_vector.push_back(std::ref(topology.atoms[atom_index]));
        }
        if (include)
            bonds.push_back(bond_atom_vector);
    }
    return std::move(bonds);
}

}
