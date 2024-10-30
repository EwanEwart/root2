#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphErrors.h>

void TGraphErrors_01()
{
   auto c {new TCanvas("c","Demo TGraphErrors", 640*1.5,640/16, 480,600)};
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
