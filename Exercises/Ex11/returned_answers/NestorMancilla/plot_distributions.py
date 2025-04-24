#!/usr/bin/env python3
import ROOT

def plot_distribution():
    f = ROOT.TFile("output.root")
    h_pileup = f.Get("h_pileup")
    
    c = ROOT.TCanvas("c", "Pileup", 800, 600)
    h_pileup.Draw("HIST")
    c.SaveAs("pileup.png")
    
    print("Saved plots as pileup.png")

if __name__ == "__main__":
    plot_distribution()
