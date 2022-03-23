6500_clampPimpleFoam_solver

Repository holding the OpenFOAM files for the solver developed in three steps, described at
- 1st step at meran.se/openfoam-pimplefoam-w-heat-transfer-1/
- 2nd step at meran.se/openfoam-pimplefoam-w-heat-transfer-2/
- 3rd step at meran.se/convective-heat-transfer-in-sugar-beet-stores/

The case files used in parallel with these development of the solver are:
- 1st step at github/meranbioph/6500_clamp_04
- 2nd step at github/meranbioph/6500_clamp_05
- 3rd step at github/meranbioph/6500_clamp_08

The solver is for a incompressible, turbulent, transient flow (pimpleFoam), with the addition of the energy equation (temperature) for two phases - gas and solid.

The following scalars where added at each step (* = a scalar field)
- 1st step: Ts*, ...
- 2nd step: Tf*, hsf, ...
- 3rd step: D_eq, Re*, hsf *, ...

There is also a porous zone in the cases, but this has no effect on the solver.
