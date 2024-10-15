#ifdef __CLING__
#pragma cling optimize(0)
#endif
void c2()
{
//=========Macro generated from canvas: c2/c2
//=========  (Tue Oct 15 15:33:08 2024) by ROOT version 6.30/08
   TCanvas *c2 = new TCanvas("c2", "c2",290,118,700,579);
   c2->Range(0,0,1,1);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetFrameBorderMode(0);
   TArrow *arrow = new TArrow(0.8724928,0.1368421,0.1045845,0.88,0.05,">");
   arrow->SetFillColor(1);
   arrow->SetFillStyle(1001);
   arrow->SetAngle(45);
   arrow->Draw();
   arrow = new TArrow(0.1489971,0.1578947,0.6590258,0.7242105,0.05,">");
   arrow->SetFillColor(1);
   arrow->SetFillStyle(1001);
   arrow->Draw();
   
   TArc *arc = new TArc(0.4548711,0.8073684,0.09097421,0,360);
   arc->SetFillColor(42);
   arc->SetFillStyle(3002);
   arc->SetLineColor(6);
   arc->Draw();
   c2->Modified();
   c2->SetSelected(c2);
   c2->ToggleToolBar();
}
