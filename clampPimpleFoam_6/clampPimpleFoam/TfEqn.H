// Solve the temperature equation for the fluid phase
{
     atf = turbulence->nut()/Prt;
     atf.correctBoundaryConditions();
     aefff = turbulence->nu()/Pr + atf;
     fvScalarMatrix TfEqn
     (
         por*fvm::ddt(Tf)
         + por*fvm::div(phi,Tf)
         - por*fvm::laplacian(aefff, Tf)
         + clampDummy*fvm::Sp(Asf*hsf/(rhof*Cpf),Tf)
         - clampDummy*Asf*hsf*(Ts)/(rhof*Cpf)
     );
    TfEqn.relax();
    TfEqn.solve();
}
