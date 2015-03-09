# generate split test header file
message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/split_test_helper.h "")
foreach(i RANGE 1 999)
  file(APPEND ${CMAKE_CURRENT_BINARY_DIR}/split_test_helper.h
    "#ifdef EIGEN_TEST_PART_${i}\n"
    "#define CALL_SUBTEST_${i}(FUNC) CALL_SUBTEST(FUNC)\n"
    "#else\n"
    "#define CALL_SUBTEST_${i}(FUNC)\n"
    "#endif\n\n"
    )
endforeach()

include_directories(${EIGEN_SOURCE_DIR}/test ${CMAKE_CURRENT_BINARY_DIR})

set( CMAKE_BUILD_TYPE "Debug" )
ei_add_test(quantity)
