// Solve the temperature equation for the solid phase
{
  // Qr = dimensionedScalar("c1", Qr.dimensions(), 1.0)*exp( 25.292 - dimensionedScalar("c2", dimTemperature, 6291.0)/Ts);
  Qr = 4 * clampDummy * dimensionedScalar("c1", Qr.dimensions(), 45.650) / (1.0 + 1.0 * exp(dimensionedScalar("c2", dimensionSet(0, 0, 0, -1, 0, 0, 0), -0.145) * (Ts - dimensionedScalar("c2", dimTemperature, 283.0))));
     fvScalarMatrix TsEqn
     (
       (rhos*Cps)*fvm::ddt(Ts)
       - (1-por)*fvm::laplacian(Ks,Ts)
       - clampDummy*Asf*hsf*(Tf)/invPor
       + clampDummy*fvm::Sp(Asf*hsf/invPor,Ts)
       - Qr*(1-por)
       //- (rhos*Cps)*(1-clampDummy)*(Tf-Ts)*dimensionedScalar("d1", dimensionSet(0, 0, -1, 0, 0, 0, 0), 0.01)
     );
    TsEqn.relax();
    TsEqn.solve();
}
