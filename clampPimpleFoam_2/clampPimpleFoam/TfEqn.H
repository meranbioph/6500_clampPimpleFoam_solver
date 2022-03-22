// Solve the temperature equation for the fluid phase
{
     atf = turbulence->nut()/Prt;
     atf.correctBoundaryConditions();
     aefff = turbulence->nu()/Pr + atf;
     fvScalarMatrix TfEqn
     (
         por*fvm::ddt(Tf)
         + por*fvm::div(phi,Tf)
         - fvm::laplacian(aefff*por, Tf)
         + clampDummy*por*Asf*hsf*(Tf-Ts)/(rhof*Cpf)
     );
    TfEqn.relax();
    TfEqn.solve();
}
