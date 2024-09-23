// TF1, TFormula, TMath
//
{
   auto f11 =
		new TF1
		(
			  "f11"// name
			, "TMath::Landau(x,[0],[1],0)" // formula using TMath
			, -5 // xmin
			, 10 // xmax
		);

   f11->SetParameters(0.2,1.3); // set two parameters

   f11->Draw();

	return;
}

