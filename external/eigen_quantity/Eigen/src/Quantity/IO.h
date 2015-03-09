#ifndef EIGEN_QUANTITY_IO_H
#define EIGEN_QUANTITY_IO_H

#include <Eigen/Core>
#include "Quantity.h"
#include <boost/units/io.hpp>

namespace Eigen {

template<typename ExpressionType, typename Unit>
class WithFormatQuantity: public Eigen::WithFormat<ExpressionType> {
public:

    typedef Eigen::WithFormat<ExpressionType> Base;

    WithFormatQuantity(const ExpressionType& matrix, const Eigen::IOFormat& format)
            : Base(matrix, format) {}

    friend std::ostream & operator << (std::ostream & s, const WithFormatQuantity& wf)
    {
        s << static_cast<const Base&>(wf);
        s << " " << Unit();
        return s;
    }
};

template<typename ExpressionType, typename Unit>
inline const WithFormatQuantity<ExpressionType, Unit> DenseBase<Quantity<ExpressionType, Unit>>::format(const Eigen::IOFormat& fmt) const {
    return WithFormatQuantity<ExpressionType, Unit>(this->nested(), fmt);
}

template<typename ExpressionType, class Unit>
std::ostream &operator<<(std::ostream &o, const DenseBase<Quantity<ExpressionType, Unit>> &q) {
    IOFormat format_specification(FullPrecision, 0, ", ", ";\n", "", "", "[", "]");
    o << q.format(format_specification);
    return o;
}

}

#endif