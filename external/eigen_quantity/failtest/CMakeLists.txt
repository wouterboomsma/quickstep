message(STATUS "Running the failtests")

ei_add_failtest("initialization_0")
ei_add_failtest("initialization_1")
ei_add_failtest("assignment_wrong_units")
ei_add_failtest("functor_wrong_return_type")
ei_add_failtest("redux_dynamic_matrix")

if (EIGEN_FAILTEST_FAILURE_COUNT)
  message(FATAL_ERROR
          "${EIGEN_FAILTEST_FAILURE_COUNT} out of ${EIGEN_FAILTEST_COUNT} failtests FAILED. "
          "To debug these failures, manually compile these programs in ${CMAKE_CURRENT_SOURCE_DIR}, "
          "with and without #define EIGEN_SHOULD_FAIL_TO_BUILD.")
else()
  message(STATUS "Failtest SUCCESS: all ${EIGEN_FAILTEST_COUNT} failtests passed.")
  message(STATUS "")
endif()


