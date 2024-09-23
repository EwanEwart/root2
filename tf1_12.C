// TF1, TFormula, Lambda
//

auto aLambda_12 { [](double x){return x+cos(x);} };
// auto aLambda_12 = [](double x){return x+cos(x);};

void tf1_12()
{
   auto f12_lambda { new TF1("f12","aLambda_12(x)",-3,5)}; // does work
   // auto f12_lambda { new TF1("f12","[0] * aLambda_12([1] + x)",-3,5)}; // does work
   // auto f12_lambda = new TF1("f12","aLambda_12(x)",-3,5); // alternative: does work
   // auto f12_lambda { new TF1("f12",[](double x){return x+cos(x);},-3,5,1)}; // doesn't work

	// parameters
	auto f12
	{
		new TF1
		(
			  "f12" // name
			, "[0]*sin(x) + [1]*cos(x)" // formula with two parameters indexed [1..2]
			, 0 // xmin
			, M_PI // xmax
		)
	};

	f12->SetParameters(-1.0, 2.0);
	f12_lambda->SetParameters(-1,1/2);


#define LAMBDA

#if defined LAMBDA
	f12_lambda->Draw();
#else
   f12->Draw();
#endif

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
TF1 fsum("f1","[&](double *x, double *p){ return p[0]*f1(x) + p[1]*f2(x); }",0,10,2);
*/
