// TF1, TFormula, parameters
// 2. Expression using variable x with parameters

void tf1_09()
{
	auto f09
	{
		new TF1
		(
			  "f09"// name
			, "[0] * x * sin( [1] * x )" // formula with parameters
			, -3.0 // xmin
			,  3.0 // xmax
		)
	};

	f09->SetParameters(10,2); // two parameters in this order

	f09->SetParNames("p1","p2"); // two parameters in this order

	f09->Draw(); // => p1 = 10 && p2 = 2

	return;
}

