/*
https://root.cern/manual/creating_a_user_application/
*/

void app_01()
{

   auto c { new TCanvas("c", "Trigonometric Functions", 400, 100, 800*2/3, 600*2/3) };

   auto f1 { new TF1("f1","sin(x)", -5, 5) };

   f1->SetTitle("f(x)=sin(x);x; sin(x)");
   f1->SetLineColor(kRed+1);
   f1->SetLineStyle(1);
   f1->SetLineWidth(1);

   f1->Draw();

}
