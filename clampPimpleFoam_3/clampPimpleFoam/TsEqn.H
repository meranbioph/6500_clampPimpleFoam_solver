// Solve the temperature equation for the solid phase
{
  // Qr = dimensionedScalar("c1", Qr.dimensions(), 1.0)*exp( 25.292 - dimensionedScalar("c2", dimTemperature, 6291.0)/Ts);
  Qr = dimensionedScalar("c1", Qr.dimensions(), 65.448) / (1.0 + exp(dimensionedScalar("c2", dimensionSet(0, 0, 0, -1, 0, 0, 0), -0.115) * (Ts - dimensionedScalar("c2", dimTemperature, 289.0))));
     fvScalarMatrix TsEqn
     (
         (rhos*Cps)*fvm::ddt(Ts)
       - clampDummy*(1-por)*fvm::laplacian(Ks,Ts)
       - clampDummy*Asf*hsf*(Tf-Ts)
       - clampDummy*Qr
     );
    TsEqn.relax();
    TsEqn.solve();
}
