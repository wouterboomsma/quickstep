# cmake_minimum_required(VERSION 2.8)

#project(quickstep)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
endif()

# Set default make type
if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE "Release" )
endif()

# Set location for parameter data
set(QUICKSTEP_DATA_DIR ${CMAKE_BINARY_DIR}/data)
# Expand variables in configuration header file, and move this to build dir
configure_file( quickstep_config.h ${CMAKE_CURRENT_BINARY_DIR}/quickstep_config.h )
# Add build-dir version of config file to includes (with expanded variables)
include_directories( ${CMAKE_CURRENT_BINARY_DIR}/ )

# Set parameters for different build types
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")

add_subdirectory(src)

