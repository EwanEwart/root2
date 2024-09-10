// TF1, TFormula
void tf1_03 ()
{
	auto f03 { new TF1("f03","[0]*pow(x,[1])",1,10)};
	f03->SetParameter(0,1);
	f03->SetParameter(1,4);
	f03->Draw();
}

