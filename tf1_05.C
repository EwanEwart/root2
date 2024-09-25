// TF1, TFormula
// 2. Expression using variable x with parameters

void tf1_05()
{
	auto f05
	{
		new TF1
		(
			"f05" // name
			,"gausn(0)*expo(3) + ypol3(5)*x" // formula with 5 parameters
			,1.0	// xmin
			,30.0 // xmax
		)
	};

	f05->SetParameters(3, 5, 7, 2, .2); // set all parameters instead of one by one

	f05->Draw();

	return;
}

