// TF1, TFormula
void tf1_05()
{
	auto f05
	{
		new TF1
		(
			"f05" // name
			,"gausn(0)*expo(3) + ypol3(5)*x" // formula with 5 parameters
			,1	// xmin
			,30 // xmax
		)
	};

	f05->SetParameters(3, 5, 7, 2, .2); // set all parameters instead of one by one

	f05->Draw();

	return;
}

