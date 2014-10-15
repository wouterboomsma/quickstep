include_directories(${quickstep_SOURCE_DIR}/include)

add_library(quickstep
  CoreGraph.cpp

  ${quickstep_SOURCE_DIR}/include/quickstep/CoreGraph.h
)