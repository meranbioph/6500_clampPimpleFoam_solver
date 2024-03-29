// Solve the temperature equation for the solid phase
{
  Qr = dimensionedScalar("c1", Qr.dimensions(), 1.0)*exp( 25.292 - dimensionedScalar("c2", dimTemperature, 6291.0)/Ts);
     fvScalarMatrix TsEqn
     (
         (rhos*Cps)*fvm::ddt(Ts)
       - clampDummy*(1-por)*fvm::laplacian(Ks,Ts)
       - clampDummy*Asf*hsf*(Tf-Ts)/invPor
       - clampDummy*Qr
     );
    TsEqn.relax();
    TsEqn.solve();
}
