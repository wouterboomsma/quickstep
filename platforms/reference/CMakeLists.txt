#---------------------------------------------------
# Quickstep Reference Platform
#
# Creates QuickstepReference library.
#
# Windows:
#   quickstep_reference.dll
#   quickstep_reference.lib
#   quickstep_reference_static.lib
# Unix:
#   libquickstep_reference.so
#   lib_quickstep_reference_static.a
#----------------------------------------------------

if(BUILD_TESTING)
    subdirs(tests)
endif(BUILD_TESTING)

set(quickstep_REFERENCE_LIBRARY_NAME quickstep_reference)

set(SHARED_TARGET ${quickstep_REFERENCE_LIBRARY_NAME})
set(STATIC_TARGET ${quickstep_LIBRARY_NAME}_static)

set(SOURCE_FILES
    src/ReferenceGaussianMoveKernel.cpp
    src/ReferenceKinematicForestKernel.cpp
    src/register_kernels.cpp
    include/ReferenceGaussianMoveKernel.h
    include/ReferenceKinematicForestKernel.h
    )

include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB CORE_HEADERS include/*.h)
install_files(/include/quickstep/cpu FILES ${CORE_HEADERS})

if(quickstep_BUILD_SHARED_LIB)
    include(CMakeListsSharedTarget.txt)
endif(quickstep_BUILD_SHARED_LIB)
if(quickstep_BUILD_STATIC_LIB)
    include(CMakeListsStaticTarget.txt)
endif(quickstep_BUILD_STATIC_LIB)