surfaceScalarField kapparhoCpbyDelta
     (
         sqr(mesh.surfaceInterpolation::deltaCoeffs())
        *Kf
        /(Cpf*rhof)
     );

     const scalar DiNum = max(kapparhoCpbyDelta).value()*runTime.deltaTValue();
     const scalar meanDiNum =
         average(kapparhoCpbyDelta).value()*runTime.deltaTValue();


Info<< " Diffusion Number mean: " << meanDiNum
    << " max: " << DiNum << endl;
