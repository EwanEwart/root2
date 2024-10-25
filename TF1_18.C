// EE
// Plot UDF
// function to plot: x^3
// type to use: double (*)(double* x, double* param)
//

double p1(double *x, double *par) { return par[0] * pow(x[0],1); };
double p2(double *x, double *par) { return par[0] * pow(x[0],2); };
double p3(double *x, double *par) { return par[0] * pow(x[0],3); };
double p34(double *x, double *par) { return par[0] * pow(x[0],3) + par[1]*pow(x[0],2) + par[2]*pow(x[0],1) + par[3]*pow(x[0],0); };
double p4(double *x, double *par) { return par[0] * pow(x[0],4); };
// ...
double(*fctn)(double*,double*){p3}; // one parameter
// double(*fctn)(double*,double*){p34}; // four parameter


void TF1_18()
{
   // TF1
   auto tf1
   {
      new TF1 
      (
         "tf1" // name
         , fctn   // double(*fctn)(double*,double*)
         , -2 * TMath::Pi()   // xmin
         , 2 * TMath::Pi()    // xmax
         , 1               // 1 nparam
         // , 4                  // 4 nparam
      )
   };
   // parameters

   // tf1->SetParameters(1); // just one parameter

   tf1->SetParameters
   (
         1. 
      ,  1. 
      , -1.
      ,  1.
   ); // four parameter

   tf1->SetRange(-3.3,3.3);
   // draw
   tf1->Draw();
}
