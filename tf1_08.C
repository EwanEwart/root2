// TF1, TFormula, Lambda
//
auto aLambda { [](double x){return x+cos(x);} };

void tf1_08()
{
   auto f08
	{
		new TF1
		(
			  "f08" // name
			, "aLambda(x)" // formula
			, -3 // xmin
			,  5 // xmax
		)
	};

   f08->Draw();

	return;
}  

