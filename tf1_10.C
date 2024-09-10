// TF1, TFormula
void tf1_10()
{
	auto f10 { new TF1("f10", "gaus(0)*expo(3)", 0, 10 ) };
	f10->SetParameters(1,2,3,4,.7);
	f10->Draw();
}

