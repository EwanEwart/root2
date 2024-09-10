// TF1, TFormula
void tf1_05()
{
	auto f05 {new TF1("f05","gausn(0)*expo(3) + ypol3(5)*x",1,30)};
	f05->SetParameters(3,5,7,2,.2);
	f05->Draw();
}

