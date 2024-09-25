// TF1, TFormula, Lambda
// 3. Lambda Expression with "variable x" | "variable x" && parameters

// .x tf1_12.C | .L tf1_12.C
// tf1_12( 1 | 2 )

auto aLambda{[](double x) { return x + cos(x); }};
// auto aLambda = [](double x){return x+cos(x);};

void tf1_12(int choice = -1)
{

   auto f12
   {
      new TF1
      (
         "f12"    // name
         , "[0]*sin(x) + [1]*cos(x)" // formula with two parameters indexed [1..2]
         , 0      // xmin
         , M_PI   // xmax
      )
   };

   auto f12_lambda { new TF1("f12","aLambda(x)",-3.0,5.0)}; // w/o params : works
   // auto f12_lambda = new TF1("f12","aLambda(x)",-3.0,5.0) ; // alternative: works
   // auto f12_lambda { new TF1("f12","[0] * aLambda([1] + x)",-3.0,5.0)}; // w params : works
   // auto f12_lambda { new TF1("f12",[&](double* x,double *p){return p[0]+cos(x[0]); } , -3.0,5.0,1) }; // works
   // auto f12_lambda { new TF1("f12","[&](double* x,double *p){return p[0]+cos(x[0]); }",-3.0,5.0,1)}; // works

   auto f1{new TF1("f1", "sin(x)", 0.0, 2 * M_PI)};
   auto f2{new TF1("f2", "cos(x)", 0.0, 2 * M_PI)};
   // auto fsum       { new TF1("fsum","[&](double* x,double *p){return p[0]*f1(x[0])  + p[1]*f2(x[0]); }", 0.0, 2*M_PI, 2) };
   // auto fsum       { new TF1("fsum", [&](double* x,double *p){return p[0]*f1(x[0])  + p[1]*f2(x[0]); },  0.0, 2*M_PI, 2) };
   auto fsum       { new TF1("fsum", [&](double* x,double *p){return p[0]*cos(x[0]) + p[1]*sin(x[0]);},  0.0, 2*M_PI, 2) };

   switch (choice)
   {
   case 1: // parameterised expression w/o lambda
      f12->SetParameters(-1.0, 2.0);
      f12->Draw();
      break;

   case 2: // lambda in parameterised expression
      f12_lambda->SetParameters(-1, 1 / 2);
      f12_lambda->Draw();
      break;

   case 3:
      f1->Draw();
      break;

   case 4:
      f2->Draw();
      break;

   default:
      cerr << "tf1_12( 1 | 2 | ... 4 )" << endl;
      break;
   };

   return;
}

/*
3 - A lambda expression with variables and parameters

Since 6.00/00:

TF1 supports using lambda expressions in the formula.

This allows, using the full C++ syntax of lambda functions
and still maintain the capability of storing the function in a file,
which cannot be done with function pointers or lambdas
not written as expression, but as code (see items below).

Example on how using lambda
to define a sum of two functions.

Note:
It is necessary to provide the number of parameters.

TF1 f1("f1","sin(x)",0,10);
TF1 f2("f2","cos(x)",0,10);
TF1 fsum("fsum","[&](double *x, double *p){ return p[0]*f1(x) + p[1]*f2(x); }", 0.0, 10.0, 2);
*/
