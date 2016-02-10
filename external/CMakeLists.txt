option(USE_SYSTEM_EIGEN "Should we use the system Eigen?" OFF)

# Eigen
if(NOT USE_SYSTEM_EIGEN)
  set(EIGEN3_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/eigen/")
endif()
find_package(Eigen3 REQUIRED)
message(STATUS "Found Eigen ${EIGEN3_VERSION} in ${EIGEN3_INCLUDE_DIR}")
list(APPEND quickstep_EXTERNAL_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})

## Optional
#list(APPEND quickstep_EXTERNAL_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/optional")

# Boost
list(APPEND quickstep_EXTERNAL_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/boost_1_60_0")
#find_package(Boost COMPONENTS system filesystem REQUIRED)
#list(APPEND quickstep_EXTERNAL_LIBRARIES ${Boost_LIBRARIES})
#list(APPEND quickstep_EXTERNAL_INCLUDE_DIRS ${Boost_INCLUDE_DIR})


# Communicate variables to parent scope
set(quickstep_EXTERNAL_INCLUDE_DIRS "${quickstep_EXTERNAL_INCLUDE_DIRS}" PARENT_SCOPE)
set(quickstep_EXTERNAL_LIBRARIES "${quickstep_EXTERNAL_LIBRARIES}" PARENT_SCOPE)



# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/eigen/cmake/")
# set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/eigen/cmake/")
#
# # CLion requires all header files to be included explicitly
# FILE (GLOB clion_all_eigen_headers_main ${CMAKE_CURRENT_SOURCE_DIR}/eigen/Eigen/*)
# FILE (GLOB_RECURSE clion_all_eigen_headers ${CMAKE_CURRENT_SOURCE_DIR}/eigen/*.h)
# FILE (GLOB clion_all_eigen_quantity_headers_main ${CMAKE_CURRENT_SOURCE_DIR}/eigen_quantity/Eigen/*)
# FILE (GLOB_RECURSE clion_all_eigen_quantity_headers ${CMAKE_CURRENT_SOURCE_DIR}/eigen_quantity/*.h)
# ADD_CUSTOM_TARGET(all_clion_eigen
#     SOURCES ${clion_all_eigen_headers_main} ${clion_all_eigen_headers} ${clion_all_eigen_quantity_headers_main} ${clion_all_eigen_quantity_headers}
# )
#
