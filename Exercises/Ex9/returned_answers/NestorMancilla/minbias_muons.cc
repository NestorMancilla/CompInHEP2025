#include "Pythia8/Pythia.h"
#include "TFile.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TStyle.h"

using namespace Pythia8;

int main() {
    gStyle->SetOptStat(1111);
    gStyle->SetOptFit(1);
    
    Pythia pythia;
    pythia.readString("Beams:eCM = 13600.");
    pythia.readString("SoftQCD:all = on");
    pythia.readString("Random:setSeed = on");
    pythia.readString("Random:seed = 0");
    pythia.init();
    
    TH1D *h_pt = new TH1D("h_pt", "Muon p_{T} Distribution;p_{T} [GeV/c];Counts", 100, 0., 20.);
    TH1D *h_eta = new TH1D("h_eta", "Muon #eta Distribution;#eta;Counts", 100, -5., 5.);
    TH1D *h_pt_selected = new TH1D("h_pt_selected", "Selected Muons (p_{T} > 5 GeV/c, |#eta| < 2.5);p_{T} [GeV/c];Counts", 50, 5., 20.);
    
    int nEvents = 100000;
    int nTotalMuons = 0;
    int nDetectedMuons = 0;

    for (int iEvent = 0; iEvent < nEvents; ++iEvent) {
        if (!pythia.next()) continue;
        
        for (int i = 0; i < pythia.event.size(); ++i) {
            Particle &part = pythia.event[i];
            
            if (abs(part.id()) == 13 && part.isFinal()) {
                nTotalMuons++;
                double pt = part.pT();
                double eta = part.eta();
                
                h_pt->Fill(pt);
                h_eta->Fill(eta);
                
                if (pt > 5. && abs(eta) < 2.5) {
                    nDetectedMuons++;
                    h_pt_selected->Fill(pt);
                }
            }
        }
    }
    
    TCanvas *c_pt = new TCanvas("c_pt", "Muon pT Distribution", 800, 600);
    h_pt->Draw();
    c_pt->SaveAs("muon_pt_distribution.png");
    
    TCanvas *c_eta = new TCanvas("c_eta", "Muon eta Distribution", 800, 600);
    h_eta->Draw();
    c_eta->SaveAs("muon_eta_distribution.png");
    
    TCanvas *c_pt_selected = new TCanvas("c_pt_selected", "Selected Muons pT Distribution", 800, 600);
    h_pt_selected->Draw();
    c_pt_selected->SaveAs("selected_muons_pt_distribution.png");
    
    TFile outFile("muon_distributions.root", "RECREATE");
    h_pt->Write();
    h_eta->Write();
    h_pt_selected->Write();
    outFile.Close();
    
    double detectionProb = (nTotalMuons > 0) ? (double)nDetectedMuons/nTotalMuons : 0.;
    std::cout << "\nDetection Probability for pT > 5 GeV/c and |η| < 2.5: " 
              << detectionProb << " (" << nDetectedMuons << "/" << nTotalMuons << ")\n";
    
    return 0;
}
