// TF1, TFormula
void tf1_04()
{
	auto f04 { new TF1("f04","gaus(0)*expo(3) + ypol3(5)*x",0,25)};
	f04->SetParameters(4,2,7,3,.1);
	f04->Draw();
}

