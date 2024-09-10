// TF1, TFormula
void tf1_01()
{
   auto fa1 { new TF1("fa1","sin(x)/x",0,10)};
   fa1->Draw();
}
