// Solve the temperature equation for the solid phase
{
  // Qr = dimensionedScalar("c1", Qr.dimensions(), 1.0)*exp( 25.292 - dimensionedScalar("c2", dimTemperature, 6291.0)/Ts);
  Qr = QrMulti * clampDummy * dimensionedScalar("c1", Qr.dimensions(), 45.650) / (1.0 + 1.0 * exp(dimensionedScalar("c2", dimensionSet(0, 0, 0, -1, 0, 0, 0), -0.145) * (Ts - dimensionedScalar("c3", dimTemperature, 283.0))));
     fvScalarMatrix TsEqn
     (
       (invPor*rhos*Cps)*fvm::ddt(Ts)
       - clampDummy*invPor*fvm::laplacian(Ks,Ts)
       - clampDummy*Asf*hsf*(Tf)
       + clampDummy*fvm::Sp(Asf*hsf,Ts)
       - clampDummy*Qr
       - covDummy*dimensionedScalar("d1", dimensionSet(0, 0, 0, 0, 0, 0, 0), 100.0)*fvm::laplacian(Ks,Ts)
       - inDummy*dimensionedScalar("d2", dimensionSet(0, 0, 0, 0, 0, 0, 0), 100.0)*fvm::laplacian(Ks,Ts)
       - outDummy*rhos*Cps*(Tf-Ts)*dimensionedScalar("d3", dimensionSet(0, 0, -1, 0, 0, 0, 0), 0.01)
     );
    TsEqn.relax();
    TsEqn.solve();
}
