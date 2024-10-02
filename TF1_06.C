// TF1, TFormula, TMath
// https://root.cern/doc/master/namespaceTMath.html
// https://en.wikipedia.org/wiki/Struve_function
// 2. Expression using variable x (with parameters)

void tf1_06()
{
	auto f06
	{
		new TF1
		(
			  "f06" // name
			, "TMath::DiLog(x)" // TMath formula : Modified Struve functions of order 1.
			, 1.0  // xmin
			, 10.0 // xmax
		)
	};

	f06->Draw();

	return;
}

