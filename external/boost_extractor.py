#!/usr/bin/env python
#
# This is an adaptation of the rename.py script:
# Copyright Artyom Beilis 2009. Use, modification and
# distribution is subject to the Boost Software License, Version
# 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)
#
# Modified for use specifically in quickstep, adding additional
# replacements of guards (including those not starting with "BOOST"),
# and replacing a few additional top-level struct names that otherwise
# conflict with existing boost installations

import re
import sys
import os
import os.path
import StringIO

class SyntaxError(Exception):
    def __init__(self,message):
        self.message=message

class tockenizer:
    def __init__(self,input):
        self.input=input
    def chr_end(self,line,pos,c):
        size=len(line)
        while pos<size:
            if line[pos:pos+2]=="\\\\" or line[pos:pos+2]=='\\'+c:
                pos+=2
            elif line[pos]==c:
                return pos+1
            else:
                pos+=1
        return -1
    def tockens(self):
        line=self.input.readline()
        while line:
            size=len(line)
            i=0
            while i<size:
                if line[i].isalpha() or line[i]=='_':
                    n=1
                    while i+n<size and (line[i+n].isalpha() or line[i+n]=='_' or line[i+n].isdigit()):
                        n+=1
                    yield line[i:i+n]
                    i+=n
                elif line[i:i+2]==r'//':
                    yield line[i:]
                    i=size
                elif line[i:i+2]==r'/*':
                    end=line.find(r'*/',i)
                    if end!=-1:
                        yield line[i:end+2]
                        i=end+2
                    else:
                        res=line[i:]
                        line=self.input.readline()
                        while line:
                            end=line.find(r'*/')
                            if end==-1:
                                res+=line
                                line=self.input.readline()
                            else:
                                res+=line[:end+2]
                                size=len(line)
                                i=end+2;
                                yield res
                                break
                        size=len(line)
                elif line[i]=='"' or line[i]=="'":
                    c=line[i]
                    end=self.chr_end(line,i+1,c)
                    if end!=-1:
                        yield line[i:end]
                        i=end
                    else:
                        res=line[i:]
                        line=self.input.readline()
                        while line:
                            end=self.chr_end(line,0,c)
                            if end==-1:
                                res+=line
                                line=self.input.readline()
                            else:
                                res+=line[:end]
                                size=len(line)
                                i=end;
                                yield res
                                break
                        size=len(line)
                elif i+1==size and line[i:i+1]=='\\\n':
                    yield '\\\n'
                    i+=2
                else:
                    yield line[i]
                    i+=1
            line=self.input.readline()


class renamer:
    fname=re.compile(r'^(\w+)$')
    ident=re.compile(r'^[a-zA-Z_][a-zA-Z_0-9]*$')
    def __init__(self,input,output,namespace,newdir=''):
        self.input=input
        self.output=output
        self.namespace=namespace
        self.newdir=newdir
    def process_tocken(self,tocken):
        if self.ident.match(tocken):
            tocken=tocken.replace('BOOST',namespace.upper())
            tocken=tocken.replace('boost',namespace)
        self.output.write(tocken)
    def process_all(self,lst):
        for tocken in lst:
            self.process_tocken(tocken)
    def convert_path(self,lst):
        self.output.write('<'+self.newdir)
        self.process_all(lst[2:])
        
    def rename(self):
        parser=tockenizer(self.input)
        state='Normal'
        substate=None
        lst=[]
        inc=re.compile(r'^"boost(/.*)"$')
        for tocken in parser.tockens():
            lst.append(tocken)
            if state=='Normal' and tocken=='<':
                state='<'
                continue
            elif state=='<' and tocken=='boost':
                state='boost'
                continue
            elif state=='boost' and tocken=='/':
                state='/'
                continue
            elif state=='/' and self.fname.match(tocken):
                state='dir'
                continue
            elif state=='dir' and tocken=='/':
                state='/'
                continue
            elif state=='dir' and tocken=='.':
                state='.'
                continue
            elif state=='.' and (tocken=='ipp' or tocken=='h' or tocken=='hpp'):
                state='hpp'
                continue
            elif state=='dir' and tocken=='>':
                self.convert_path(lst)
                lst=[]
            elif state=='hpp' and tocken=='>':
                self.convert_path(lst)
                lst=[]
            elif state=='Normal' and inc.match(tocken):
                m=inc.match(tocken)
                lst[0]='"'+self.newdir+m.group(1)+'"'
            state='Normal'
            self.process_all(lst)
            lst=[]
def is_cpp(name):
    for suffix in ['.hpp','.h','.ipp','.cpp','.c','.inl','inc','.SUNWCCh','.cxx','.cc' ]:
        if name.endswith(suffix):
            return True
    if os.path.basename(os.path.dirname(name)) in ['tr1','cpp_c_headers']:
        return True
    return False

def is_ign(name):
    ign=['.vcproj', '.sln', '.v2', '.html', '.cmake', '.txt', '.qbk',\
         '.mak', '.sh', '.pl', '.r', '.css', '.png', '.doc', '.vsprops','.mcp'\
         '.xml','.xsd','.jam','.htm','.bat','.xml','.dtd','.zip',\
         '.gif','.sty','.pdf','.csh','.w','.fig','.graffle','.jpg',\
         '.dot','.cfg','.dimacs','.expected','.dat','.js','.py','.svg','.jpeg','.mml',\
         '.input','.flex','.hdf','.manifest','.xsl','.m4','.rst','.rsa','.pyste',\
         '.ok','.err1','.err2','.err3','.mini','.db','.toyxml','.quickbook','.gold',\
         '.cmd','.toc','.pem','.xls','.rsp','.reno','.output','.log','.in','.am']
    for suffix in ign:
        if name.endswith(suffix):
            return True
    if os.path.basename(os.path.dirname(name)) in ['doc','boehm_gc','debian']:
        return True
    name=os.path.basename(name)
    if name in ['Jamfile', 'Makefile','Jamroot','INSTALL','README','LICENSE','Thumbs.db','TODO','NEWS','configure','sublibs','Changelog']:
        return True
    return False

def rename_one(name,namespace,newdir):
    if is_cpp(name):
        print "Processing file %s" % name
        fin=file(name)
        buffer=StringIO.StringIO()
        ren=renamer(fin,buffer,namespace,newdir)
        ren.rename()
        fin.close()
        fout=file(name,'w')
        buffer.seek(0)
        line=buffer.readline()
        while line:
            fout.write(line)
            line=buffer.readline()
        fout.close()

    elif is_ign(name):
        pass
    else:
        print "Warning!!!!!!!!!! Unlnown file type %s" % name
        print "--------------------Ignoring----------------"
        rep=file('warning.log','a')
        rep.write('Unlnown file type %s\n' % name)
        rep.close()

def rename_recursively(dir,namespace,newdir):

    pattern = re.compile(r"^[^#]*#\s*ifndef\s+([^\n]+)\n#\s*define\s+\1", re.M+re.S)
    cpp_variables = []

    for root,dirs,files in os.walk(dir):
        for file in files:
            filename = os.path.join(root,file)
            rename_one(filename,namespace,newdir)


if __name__=='__main__':

    import optparse
    
    # Parse command line options
    parser = optparse.OptionParser()
    parser.add_option("--output-dir", dest="output_directory", 
                      help="Where to dump boost files")
    parser.add_option("--boost-dir", dest="boost_directory", 
                      help="Boost base directory")
    parser.add_option("--namespace-prefix", dest="namespace_prefix", 
                      help="Target namespace prefix")
    (options, args) = parser.parse_args()


    # Define relevant headers
    boost_headers = ["boost/algorithm/string.hpp",
                     "boost/units/systems/si.hpp",
                     "boost/units/systems/cgs.hpp",
                     "boost/units/systems/si/io.hpp",
                     "boost/units/base_units/metric/angstrom.hpp",
                     "boost/units/systems/angle/degrees.hpp",
                     "boost/units/systems/si/codata/physico-chemical_constants.hpp",
                     "boost/units/systems/si/codata/electromagnetic_constants.hpp",
                     "boost/typeof/incr_registration_group.hpp",
                     "boost/units/systems/si/prefixes.hpp",
                     "boost/units/physical_dimensions/molar_energy.hpp",
                     "boost/units/cmath.hpp",
                     "boost/units/systems/cgs/mass.hpp",
                     "boost/optional.hpp",
                     "boost/exception/info.hpp",
                     "boost/property_tree/ptree.hpp",
                     "boost/property_tree/xml_parser.hpp",
                     "boost/range/adaptor/transformed.hpp",
                     "boost/spirit/include/qi.hpp",
                     "boost/spirit/include/phoenix_object.hpp",
                     "boost/spirit/include/phoenix_operator.hpp"]

    # Run boost BCP utility to extract into target directory
    command_line = "%s/dist/bin/bcp --boost=%s %s %s" % (options.boost_directory,
                                                         options.boost_directory,
                                                         " ".join(boost_headers),
                                                         options.output_directory)
    os.system(command_line)


    # Original rename.py code
    path=options.output_directory
    namespace=options.namespace_prefix+"boost"
    if namespace.lower()!=namespace:
        print "Namespace should be lowercase"
        sys.exit(1)
    newdir=namespace
    ren=rename_recursively(path,namespace,newdir)
    boost_dir=os.path.join(path,'boost')
    new_dir=os.path.join(path,newdir)
    if os.path.isdir(boost_dir):
        os.rename(boost_dir,new_dir)

            
    # Ensure that all guards have been replaced
    pattern = re.compile(r"^[^#]*#\s*ifndef\s+([^\n]+)\n#\s*define\s+\1", re.M+re.S)
    cpp_variables = []
    for path, dirs, files in os.walk(options.output_directory):
        for filename in files:
            print filename

            full_filename = os.path.join(path, filename)

            f = open(full_filename)
            content = f.read()
            f.close()

            match = pattern.match(content)
            if match:
                if not match.group(1).startswith(namespace.upper()):
                    cpp_variables.append(match.group(1))

    # Construct single pattern of all matches
    pattern = r"\b"+re.escape(cpp_variables[0])
    for cpp_variable in cpp_variables[1:]:
        pattern += "|" + r"\b"+re.escape(cpp_variable)
    cpp_variable_pattern = re.compile(pattern)

    # Not only replace guards themselves, but also all references to them
    for path, dirs, files in os.walk(options.output_directory):
        for filename in files:
            filename = os.path.join(path, filename)
        
            f = open(filename)
            content = f.read()
            f.close()

            content = cpp_variable_pattern.sub(r"%s\g<0>" % namespace.upper(), content) 

            # One specific top-level struct occurrence must be renamed as well
            if "mpl/aux_/adl_barrier.hpp" in filename:
                content = content.replace("MPL_AUX_ADL_BARRIER_NAMESPACE mpl_",
                                          "MPL_AUX_ADL_BARRIER_NAMESPACE %smpl_" % options.namespace_prefix)
                content = content.replace("MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace mpl_ {",
                                          "MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace %smpl_ {" % options.namespace_prefix)
            if "type_traits/integral_constant.hpp" in filename:
                content = content.replace("namespace mpl_",
                                          "namespace %smpl_" % options.namespace_prefix)
                content = content.replace("using ::mpl_::",
                                          "using ::%smpl_::" % options.namespace_prefix)
                
            f = open(filename, "w")
            f.write(content)
            f.close()

