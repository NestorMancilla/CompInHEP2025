// ROOT macro file for plotting example B4 ntuple
//
// Can be run from ROOT session:
// root[0] .x plotNtuple.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");

  // Draw histos filled by Geant4 simulation
  //

  // Open file filled by Geant4 simulation
  //TFile f("B4.root");
  //TFile f("electron_10GeV_water.root");
  //TFile f("proton_10GeV_water.root");
  TFile f("alpha_10GeV_water.root");
  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1000, 1000);
  c1->Divide(2,2);

  // Get ntuple
  TNtuple* ntuple = (TNtuple*)f.Get("B4");

  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  ntuple->Draw("Eabs");

  // Draw Labs histogram in the pad 2
  c1->cd(2);
  ntuple->Draw("Labs");

  // Draw Egap histogram in the pad 
  c1->cd(3);
  //set logarithmic scale for y
  //gPad->SetLogy(1);
  ntuple->Draw("Egap");

  // Draw Lgap histogram in the pad 4
  c1->cd(4);
  //set logarithmic scale for y
  //gPad->SetLogy(1); 
  ntuple->Draw("Lgap");

  //c1->SaveAs("plots/electron_10GeV_water.png");  // PNG
  //c1->SaveAs("plots/electron_10GeV_water.pdf");  // PDF

  //c1->SaveAs("plots/proton_10GeV_water.png");  // PNG
  //c1->SaveAs("plots/proton_10GeV_water.pdf");  // PDF

  c1->SaveAs("plots/alpha_10GeV_water.png");  // PNG
  c1->SaveAs("plots/alpha_10GeV_water.pdf");  // PDF

}
