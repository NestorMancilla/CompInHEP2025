void plot_HDECAY_width() {
    TGraph *graph = new TGraph();

    ifstream file("data.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open data file!" << endl;
        return;
    }

    double mh, width;
    int point = 0;
    while (file >> mh >> width) {
        graph->SetPoint(point, mh, width);
        point++;
    }
    file.close();

    TCanvas *canvas = new TCanvas("canvas", "Higgs Width vs Mass", 800, 600);

    canvas->SetLogy();
    graph->SetTitle("SM Higgs Width vs Mass;M_H [GeV];#Gamma_{h} [GeV]");
    graph->SetLineColor(kBlue);
    graph->SetLineWidth(2);
    graph->Draw("AL");
    canvas->SaveAs("HDECAY_width.png");
    canvas->SaveAs("HDECAY_width.pdf");
}
