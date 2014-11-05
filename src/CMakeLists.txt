set(quickstep_SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/quickstep)
include_directories(${quickstep_SOURCE_DIR}/include)


add_library(quickstep
  CoreGraph.cpp
  Bond.cpp
  BondGraph.cpp
  DisjointSet.cpp
  KinematicForest.cpp
  VarietyChasse.cpp
  CofMChasse.cpp
  FreeBondRotateChasse.cpp
  math/primitives.cpp

  ${quickstep_SOURCE_DIR}/include/quickstep/Bond.h
  ${quickstep_SOURCE_DIR}/include/quickstep/BondGraph.h
  ${quickstep_SOURCE_DIR}/include/quickstep/DisjointSet.h
  ${quickstep_SOURCE_DIR}/include/quickstep/KinematicForest.h
  ${quickstep_SOURCE_DIR}/include/quickstep/VarietyChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/CofMChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/FreeBondRotateChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/infnan.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/math.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/primitives.h
)
