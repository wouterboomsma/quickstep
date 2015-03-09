project(EigenQuantity)

cmake_minimum_required(VERSION 2.8.2)

# Attempt to detect Eigen source directory
if (NOT EIGEN_SOURCE_DIR)
  get_filename_component(PARENT_DIRECTORY ${CMAKE_SOURCE_DIR} DIRECTORY)
  if (EXISTS "${PARENT_DIRECTORY}/Eigen")
    set(EIGEN_SOURCE_DIR "${PARENT_DIRECTORY}/Eigen")
  endif()
endif()

find_package(Boost 1.50)

# Enable C++11 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
endif()

# similar to set_target_properties but append the property instead of overwriting it
macro(ei_add_target_property target prop value)

  get_target_property(previous ${target} ${prop})
  # if the property wasn't previously set, ${previous} is now "previous-NOTFOUND" which cmake allows catching with plain if()
  if(NOT previous)
    set(previous "")
  endif(NOT previous)
  set_target_properties(${target} PROPERTIES ${prop} "${previous} ${value}")
endmacro(ei_add_target_property)

include_directories(${EIGEN_SOURCE_DIR} ${CMAKE_SOURCE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(EigenConfigureTesting)

add_subdirectory(test)

option(EIGEN_FAILTEST "Enable failtests." ON)
if(EIGEN_FAILTEST)
  add_subdirectory(failtest)
endif()

