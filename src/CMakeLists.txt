# Setup configuration file in build directory
configure_file( ${PROJECT_SOURCE_DIR}/include/quickstep_config.h.in ${PROJECT_BINARY_DIR}/quickstep_config.h )
include_directories( ${PROJECT_BINARY_DIR}/ )
include_directories( ${quickstep_EXTERNAL_INCLUDE_DIRS}/ )

# Add library
add_library(quickstep
    BondGraph.cpp
    DisjointSet.cpp
    Element.cpp
    KinematicForest.cpp
    Topology.cpp
    Selection.cpp
    MoveInfo.cpp
    moves/CompositeMove.cpp
    moves/MixtureMove.cpp
    moves/CofMMove.cpp
    moves/StdDoFMove.cpp
    moves/FreeBondRotateMove.cpp
    moves/InterpolatorMove.cpp
    moves/SymmetrizedMove.cpp
    moves/GaussianMove.cpp
    moves/Move.cpp
    MolecularParameters.cpp
    MoveParameters.cpp
    MoveFactory.cpp
    dofControllers/StdDoFController.cpp
    dofs/Dof.cpp
    dofs/LengthDof.cpp
    dofs/AngleDof.cpp
    dofs/DihedralDof.cpp

    ${PROJECT_SOURCE_DIR}/include/quickstep/BondGraph.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/DisjointSet.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/KinematicForest.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/MoveInfo.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/CompositeMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/MixtureMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/CofMMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/StdDoFMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/FreeBondRotateMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/InterpolatorMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/GaussianMove.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/moves/Move.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/Topology.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/Selection.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/MolecularParameters.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/MoveParameters.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/MoveFactory.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/dofControllers/StdDoFController.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/dofs/Dof.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/dofs/LengthDof.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/dofs/AngleDof.h
    ${PROJECT_SOURCE_DIR}/include/quickstep/dofs/DihedralDof.h
)

# Link with external libraries
target_link_libraries(quickstep ${quickstep_EXTERNAL_LIBRARIES})

# Installation properties
set_target_properties(quickstep PROPERTIES
    PUBLIC_HEADER "Bond.h;BondGraph.h;${PROJECT_BINARY_DIR}/config.h") # TODO: add all headers (for installation purposes only)
# install(TARGETS quickstep
#   EXPORT quickstepTargets
#   RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
#   LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
#   PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/quickstep"
#     COMPONENT dev)
