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
         + clampDummy*fvm::Sp(Asf*hsf/(rhof*Cpf*por),Tf)
         - clampDummy*Asf*hsf*(Ts)/(rhof*Cpf*por)
     );
    TfEqn.relax();
    TfEqn.solve();
}
