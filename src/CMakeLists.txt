set(quickstep_SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/quickstep)
include_directories(${quickstep_SOURCE_DIR}/include)


add_library(quickstep
  Bond.cpp
  BondGraph.cpp
  CoreGraph.cpp
  DisjointSet.cpp
  Element.cpp
  KinematicForest.cpp
  Topology.cpp
  VarietyChasse.cpp
  CofMChasse.cpp
  StdDoFChasse.cpp
  FreeBondRotateChasse.cpp
  math/primitives.cpp
  dofControllers/StdDoFController.cpp

  ${quickstep_SOURCE_DIR}/include/quickstep/Bond.h
  ${quickstep_SOURCE_DIR}/include/quickstep/BondGraph.h
  ${quickstep_SOURCE_DIR}/include/quickstep/DisjointSet.h
  ${quickstep_SOURCE_DIR}/include/quickstep/KinematicForest.h
  ${quickstep_SOURCE_DIR}/include/quickstep/VarietyChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/CofMChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/StdDoFChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/FreeBondRotateChasse.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/infnan.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/math.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/primitives.h
  ${quickstep_SOURCE_DIR}/include/quickstep/dofControllers/StdDoFController.h
)
