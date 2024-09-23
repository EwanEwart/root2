// TF1, TFormula, parameters
//
void tf1_09()
{
	auto f09
	{
		new TF1
		(
			  "f09"// name
			, "[0] * x * sin( [1] * x )" // formula with parameters
			, -3
			,  3
		)
	};

	f09->SetParameters(10,2); // two parameters in this order

	f09->SetParNames("p1","p2"); // two parameters in this order

	f09->Draw(); // => p1 = 10 && p2 = 2

	return;
}

