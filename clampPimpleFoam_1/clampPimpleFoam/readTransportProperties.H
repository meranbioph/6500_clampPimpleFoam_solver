//
singlePhaseTransportModel laminarTransport(U, phi);
// Prandtl number - fluid:fluid [-]
dimensionedScalar Pr("Pr", dimless, laminarTransport);
// Turbulent Prandtl  number - fluid:fluid [-]
dimensionedScalar Prt("Prt", dimless, laminarTransport);
