// TF1, TFormula, Lambda
// 3. Lambda Expression with variable x (and parameters)

auto aLambda { [](double x){return x+cos(x);} };

void tf1_08()
{
   auto f08
	{
		new TF1
		(
			  "f08" // name
			, "aLambda(x)" // formula
			, -3.0 // xmin
			,  5.0 // xmax
		)
	};

   f08->Draw();

	return;
}  
