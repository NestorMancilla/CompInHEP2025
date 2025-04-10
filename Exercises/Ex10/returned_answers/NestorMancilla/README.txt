///
The Makefile in the B4a-build is the one from Geant4. I produced the plots manually
using the plotNtuple.C script for each condition.

The plots can be found in the B4a-build/plots folder.
The detector conditions are:


src/DetectorConstruction.cc file
Detector Type: Sampling Calorimeter (alternating absorber and active layers).
Materials:
Absorber: Lead (Pb).
Active Medium: Liquid Argon (LAr).
Surroundings: Vacuum ("Galactic").
Geometry:
10 layers, each with 10 mm Pb + 5 mm LAr.
10cm×10cm×15cm.

To change the absorber, I manually change the B4a/src/DetectorConstruction.cc

  // Water absorber
  G4double a;  // mass of a mole;
  G4double z;  // z=mean number of protons;
  G4double density;
  G4int ncomponents, natoms;
  a = 1.01 * g / mole;
  G4Element* elH  = new G4Element("Hydrogen", "H", z = 1., a);

  a = 16.00 * g / mole;
  G4Element* elO  = new G4Element("Oxygen", "O", z = 8., a);

  density = 1.000 * g / cm3;
  G4Material* H2O = new G4Material("Water", density, ncomponents = 2);
  H2O->AddElement(elH, natoms = 2);
  H2O->AddElement(elO, natoms = 1);
