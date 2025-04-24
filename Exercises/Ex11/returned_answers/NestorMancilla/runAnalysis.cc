#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"

int main() {
  TFile *f = TFile::Open("/Users/nestorma/Documents/Helsinki/HEP_course/Coffea/DYJetsToLL.root");
  TTree *tree = (TTree*)f->Get("Events");
  
  gSystem->Load("libMyAnalysis.so");
  
  tree->Process("MyAnalysis+"); 
  
  return 0;
}
