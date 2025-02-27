#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"

int main() {
    gRandom = new TRandom();

    TFile *file = new TFile("data.root", "RECREATE");

    TTree *tree = new TTree("tree", "Tree with normally distributed random numbers");

    float random_number;

    tree->Branch("random_number", &random_number, "random_number/F");

    for (int i = 0; i < 1000; i++) {
        random_number = gRandom->Gaus(0, 1); // Mean = 0, Sigma = 1
        tree->Fill();
    }

    file->Write();
    file->Close();

    return 0;
}
