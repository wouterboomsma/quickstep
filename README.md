# Quickstep

Quickstep is a library of internal coordinates Monte Carlo moves for
molecular simulations, with the intention of being generally
applicable with any choice of molecular simulation framework. It is
still under heavy development, and much of the API is still in flux.
We expect to release an early beta later this year.

Currently, the library contains:
* Topology generation for definition of internal coordinates
* Gaussian moves for dihedrals/angles, with associated parameters for
standard sidechain rotamer sets.
* Interpolation moves, providing the ability to apply perturbations gradually
through a number of iterations
* Mixture and Composite moves, making it possible to define weighted averages of moves, supporting correct calculation of bias.