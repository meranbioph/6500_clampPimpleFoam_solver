//
singlePhaseTransportModel laminarTransport(U, phi);

// Prandtl number - fluid:fluid [-]
dimensionedScalar Pr("Pr", dimless, laminarTransport);

// Turbulent Prandtl  number - fluid:fluid [-]
dimensionedScalar Prt("Prt", dimless, laminarTransport);

// Specific heat capacity - fluid [J/(kg.K)]
dimensionedScalar Cpf("Cpf", dimensionSet(0, 2, -2, -1, 0, 0, 0), laminarTransport);

// Specific heat capacity - solid [J/(kg.K)]
dimensionedScalar Cps("Cps", dimensionSet(0, 2, -2, -1, 0, 0, 0), laminarTransport);

// Density - fluid [kg/m3]
dimensionedScalar rhof("rhof", dimensionSet(1, -3, 0, 0, 0, 0, 0), laminarTransport);

// Density - solid [kg/m3]
dimensionedScalar rhos("rhos", dimensionSet(1, -3, 0, 0, 0, 0, 0), laminarTransport);

// Thermal conductivity - solid:solid [W/(m.K)]
dimensionedScalar Ks("Ks", dimensionSet( 1, 1, -3, -1, 0, 0, 0), laminarTransport);

// Specific area of solid [m2/m3 = 1/m]
dimensionedScalar Asf("Asf", dimensionSet( 0, -1, 0, 0, 0, 0, 0), laminarTransport);

// Convection coefficient - fluid:solid. [W/(m2.K)]
dimensionedScalar hsf("hsf", dimensionSet( 1, 0, -3, -1, 0, 0, 0), laminarTransport);

// Inverse porosity [ - ]
dimensionedScalar invPor("invPor", dimensionSet(0, 0, 0, 0, 0, 0, 0), laminarTransport);
