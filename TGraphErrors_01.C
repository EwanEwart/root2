void TGraphErrors_01()
{
   auto c {new TCanvas("c","Demo TGraphErrors",600,400)};
   auto g{new TGraph("ExampleData.txt", "%lg %lg")};
   auto gr{new TGraphErrors("ExampleData.txt")};
   g->Draw("AP");
   g->Draw("C");
   gr->Draw("SAME");
}
