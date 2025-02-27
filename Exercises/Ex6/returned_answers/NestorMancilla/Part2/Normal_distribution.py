import ROOT

file = ROOT.TFile("data.root", "RECREATE")
tree = ROOT.TTree("tree", "Tree with random numbers")
random_number = ROOT.std.vector('float')()
tree.Branch("random_number", random_number)

gRandom = ROOT.TRandom()
for _ in range(1000):
    random_number.push_back(gRandom.Gaus(0, 1))
    tree.Fill()

file.Write()
file.Close()

file = ROOT.TFile("data.root", "READ")
tree = file.Get("tree")
hist = ROOT.TH1F("hist", "Normally Distributed Random Numbers", 100, -4, 4)

hist.SetFillColor(ROOT.kYellow)
tree.Draw("random_number>>hist")

canvas = ROOT.TCanvas()
hist.Fit("gaus")
canvas.SaveAs("histogram.pdf")
file.Close()

