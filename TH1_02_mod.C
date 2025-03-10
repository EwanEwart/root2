#ifdef __CLING__
#pragma cling optimize(0)
#endif
void TH1_02_mod()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Nov 13 14:59:30 2024) by ROOT version 6.30/08
   TCanvas *c1 = new TCanvas("c1", "c1",521,130,700,500);
   c1->Range(-0.625,3.121875,5.625,16.90313);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h__1 = new TH1F("h__1","histogramme from file data",10,0,5);
   h__1->SetBinContent(1,10);
   h__1->SetBinContent(2,15);
   h__1->SetBinContent(3,10);
   h__1->SetBinContent(4,11);
   h__1->SetBinContent(5,13);
   h__1->SetBinContent(6,10);
   h__1->SetBinContent(7,12);
   h__1->SetBinContent(8,9);
   h__1->SetBinContent(9,5);
   h__1->SetBinContent(10,5);
   h__1->SetEntries(100);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("h");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 100    ");
   ptstats_LaTex = ptstats->AddText("Mean  =  2.214");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  1.312");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h__1);
   
   TF1 *PrevFitTMP2 = new TF1("PrevFitTMP","[0]*x*x*x+[1]*x*x+[2]*x",0,5, TF1::EAddToList::kNo);
   PrevFitTMP2->SetFillColor(19);
   PrevFitTMP2->SetFillStyle(0);
   PrevFitTMP2->SetLineColor(2);
   PrevFitTMP2->SetLineWidth(2);
   PrevFitTMP2->SetChisquare(8.325479);
   PrevFitTMP2->SetNDF(7);
   PrevFitTMP2->GetXaxis()->SetLabelFont(42);
   PrevFitTMP2->GetXaxis()->SetTitleOffset(1);
   PrevFitTMP2->GetXaxis()->SetTitleFont(42);
   PrevFitTMP2->GetYaxis()->SetLabelFont(42);
   PrevFitTMP2->GetYaxis()->SetTitleFont(42);
   PrevFitTMP2->SetParameter(0,0.6932221);
   PrevFitTMP2->SetParError(0,0.3159156);
   PrevFitTMP2->SetParLimits(0,0,0);
   PrevFitTMP2->SetParameter(1,-6.761887);
   PrevFitTMP2->SetParError(1,2.188482);
   PrevFitTMP2->SetParLimits(1,0,0);
   PrevFitTMP2->SetParameter(2,17.54133);
   PrevFitTMP2->SetParError(2,3.625481);
   PrevFitTMP2->SetParLimits(2,0,0);
   PrevFitTMP2->SetParent(h__1);
   h__1->GetListOfFunctions()->Add(PrevFitTMP2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h__1->SetLineColor(ci);
   h__1->GetXaxis()->SetLabelFont(42);
   h__1->GetXaxis()->SetTitleOffset(1);
   h__1->GetXaxis()->SetTitleFont(42);
   h__1->GetYaxis()->SetLabelFont(42);
   h__1->GetYaxis()->SetTitleFont(42);
   h__1->GetZaxis()->SetLabelFont(42);
   h__1->GetZaxis()->SetTitleOffset(1);
   h__1->GetZaxis()->SetTitleFont(42);
   h__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.2693696,0.9343684,0.7306304,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("histogramme from file data");
   pt->Draw();
   
   TF1 *PrevFitTMP3 = new TF1("PrevFitTMP","[0]*x*x*x+[1]*x*x+[2]*x",0,5, TF1::EAddToList::kDefault);
   PrevFitTMP3->SetFillColor(19);
   PrevFitTMP3->SetFillStyle(0);
   PrevFitTMP3->SetLineColor(2);
   PrevFitTMP3->SetLineWidth(2);
   PrevFitTMP3->SetChisquare(8.325479);
   PrevFitTMP3->SetNDF(7);
   PrevFitTMP3->GetXaxis()->SetLabelFont(42);
   PrevFitTMP3->GetXaxis()->SetTitleOffset(1);
   PrevFitTMP3->GetXaxis()->SetTitleFont(42);
   PrevFitTMP3->GetYaxis()->SetLabelFont(42);
   PrevFitTMP3->GetYaxis()->SetTitleFont(42);
   PrevFitTMP3->SetParameter(0,0.6932221);
   PrevFitTMP3->SetParError(0,0.3159156);
   PrevFitTMP3->SetParLimits(0,0,0);
   PrevFitTMP3->SetParameter(1,-6.761887);
   PrevFitTMP3->SetParError(1,2.188482);
   PrevFitTMP3->SetParLimits(1,0,0);
   PrevFitTMP3->SetParameter(2,17.54133);
   PrevFitTMP3->SetParError(2,3.625481);
   PrevFitTMP3->SetParLimits(2,0,0);
   PrevFitTMP3->Draw("same");
   c1->Modified();
   c1->SetSelected(c1);
}
