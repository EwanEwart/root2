// TF1, TFormula, TMath
void tf1_06()
{
	auto f06 {new TF1("f06","TMath::DiLog(x)",1,10)};
	f06->Draw();
}

