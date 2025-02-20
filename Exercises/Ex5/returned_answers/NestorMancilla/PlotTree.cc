#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"

int main() {
    TFile *file = new TFile("data.root", "READ");

    TTree *tree = (TTree*)file->Get("tree");

    TH1F *hist = new TH1F("hist", "Normally Distributed Random Numbers", 100, -4, 4);

    float random_number;
    tree->SetBranchAddress("random_number", &random_number);
    for (int i = 0; i < tree->GetEntries(); i++) {
        tree->GetEntry(i);
        hist->Fill(random_number);
    }

    TCanvas *canvas = new TCanvas("canvas", "Canvas", 800, 600);

    gStyle->SetOptStat(0);
    canvas->SetFillColor(kWhite);

    hist->SetLineColor(kBlack);
    hist->SetLineWidth(2);
    hist->SetFillColor(kYellow);

    hist->Draw();

    hist->GetXaxis()->SetTitle("Random Number");
    hist->GetYaxis()->SetTitle("Counts");

    hist->Fit("gaus");

    canvas->SaveAs("histogram.pdf");

    file->Close();

    return 0;
}
