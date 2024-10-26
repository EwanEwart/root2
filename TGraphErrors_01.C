void TGraphErrors_01()
{
   auto c {new TCanvas("c","Demo TGraphErrors",480,640)};
   auto g{new TGraph("ExampleData.txt", "%lg %lg")};
   auto gr{new TGraphErrors("ExampleData.txt")};

   g->SetLineWidth(3);
   g->SetLineColor(kBlue+1);
   g->Draw("AP");
   
   g->SetLineWidth(3);
   g->SetLineColor(kGreen+1);
   g->Draw("C");
   
   gr->SetLineWidth(1);
   gr->SetLineColor(kRed+2);
   gr->Draw("SAME");
}
