// TF1, TFormula, TMath
// 2. Expression using variable x with parameters

{
   auto f11 =
		new TF1
		(
			  "f11"// name
			, "TMath::Landau(x,[0],[1],0)" // formula using TMath
			, -5.0 // xmin
			, 10.0 // xmax
		);

   f11->SetParameters(0.2,1.3); // set two parameters

   f11->Draw();

	return;
}

