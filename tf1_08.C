// TF1, TFormula, Lambda
auto aLambda { [](double x){return x+cos(x);} };

void tf1_08()
{
   auto f08 {new TF1("f08","aLambda(x)",-3,5)};
   f08->Draw();
}  

