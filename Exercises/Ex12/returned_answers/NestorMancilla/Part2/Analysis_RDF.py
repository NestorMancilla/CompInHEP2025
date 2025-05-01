#!/usr/bin/env python

import datetime

import ROOT

ROOT.ROOT.EnableImplicitMT()

def main():

    df = ROOT.RDataFrame("Events", "../../../../../../RDFrame/DYJetsToLL.root")
    df_trigger = df.Filter("HLT_IsoMu24", "Events that pass the trigger")

    df_pileup = df_trigger.Define("Pileup", "PV_npvs")
    h_pileup = df_pileup.Histo1D(("h_pileup", "Pileup;Number of primary vertices;Events", 100, 0, 100), "Pileup")


    canvas_pileup = ROOT.TCanvas("pileup", "Pileup Distribution", 800, 600)
    h_pileup.Draw()
    canvas_pileup.SaveAs("pileup_distribution.png")
    
    fOUT = ROOT.TFile.Open("output.root","RECREATE")

    days = ["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
    now = datetime.datetime.now()
    m = "produced: %s %s"%(days[now.weekday()],now)
    timestamp = ROOT.TNamed(m,"")
    timestamp.Write()

    h_pileup.Write()

    fOUT.Close()

if __name__ == "__main__":
    main()
