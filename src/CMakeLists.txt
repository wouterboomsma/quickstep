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
  CompositeMove.cpp
  CofMMove.cpp
  StdDoFMove.cpp
  FreeBondRotateMove.cpp
  math/primitives.cpp
  dofControllers/StdDoFController.cpp

  ${quickstep_SOURCE_DIR}/include/quickstep/Bond.h
  ${quickstep_SOURCE_DIR}/include/quickstep/BondGraph.h
  ${quickstep_SOURCE_DIR}/include/quickstep/DisjointSet.h
  ${quickstep_SOURCE_DIR}/include/quickstep/KinematicForest.h
  ${quickstep_SOURCE_DIR}/include/quickstep/CompositeMove.h
  ${quickstep_SOURCE_DIR}/include/quickstep/CofMMove.h
  ${quickstep_SOURCE_DIR}/include/quickstep/StdDoFMove.h
  ${quickstep_SOURCE_DIR}/include/quickstep/FreeBondRotateMove.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/infnan.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/math.h
  ${quickstep_SOURCE_DIR}/include/quickstep/math/primitives.h
  ${quickstep_SOURCE_DIR}/include/quickstep/dofControllers/StdDoFController.h
)
