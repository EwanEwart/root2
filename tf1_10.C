// TF1, TFormula
//
void tf1_10()
{
	auto f10
	{
		new TF1
		(
			  "f10" // name
			, "gaus(0)*expo(3)" // formula holding five parameters
			, 0 // xmin
			, 10 // xmax
		)
	};

	f10->SetParameters( 1, 2, 3, 4, .7 ); // set five parameters

	f10->Draw();

	return;
}

