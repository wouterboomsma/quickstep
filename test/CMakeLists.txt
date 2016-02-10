add_executable(test_topology test_topology.cpp)
add_dependencies(test_topology quickstep)
set_target_properties(test_topology
    PROPERTIES
    LINK_FLAGS "${EXTRA_COMPILE_FLAGS}"
    COMPILE_FLAGS "${EXTRA_COMPILE_FLAGS}")
target_link_libraries(test_topology ${quickstep_LIBRARIES})
