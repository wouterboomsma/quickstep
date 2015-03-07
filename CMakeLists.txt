cmake_minimum_required(VERSION 2.8.8)

# Set project name and languages used in project
project(quickstep CXX)

# Set version information
set(quickstep_MAJOR_VERSION 0)
set(quickstep_MINOR_VERSION 1)
set(quickstep_PATCH_VERSION 0)
set(quickstep_VERSION
  ${quickstep_MAJOR_VERSION}.${quickstep_MINOR_VERSION}.${quickstep_PATCH_VERSION})

# Set cmake module directory
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_CURRENT_BINARY_DIR}" ${CMAKE_MODULE_PATH} )

# Set policies
include(policies NO_POLICY_SCOPE)

# Add C++11 support
include(c++11)

# Set build type parameters
include(buildType)

# Setup installation locations
include(installation_locations)

# Set location for parameter data
set(QUICKSTEP_DATA_DIR ${CMAKE_BINARY_DIR}/data)

# Traverse sources for external libraries
add_subdirectory(external)

# Set up include directories
set(quickstep_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}" "${quickstep_EXTERNAL_INCLUDE_DIRS}")
include_directories(${quickstep_INCLUDE_DIRS})

# Traverse project sources
add_subdirectory(src)

# Create the Config and Version files (in order to support find_package(quickstep)
set(CONF_INCLUDE_DIRS ${quickstep_INCLUDE_DIRS})
configure_file("${PROJECT_SOURCE_DIR}/cmake/quickstepConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/quickstepConfig.cmake" @ONLY)
configure_file("${PROJECT_SOURCE_DIR}/cmake/quickstepConfigVersion.cmake.in"
  "${PROJECT_BINARY_DIR}/quickstepConfigVersion.cmake" @ONLY)

