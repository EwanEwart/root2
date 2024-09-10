// TFormula : [0] * sin(x) + [1] * exp(-[2] * x )
void tf1_02()
{
	auto f02 {new TF1("f02","[0]*sin(x) + [1]*exp(-[2]*x)",0,10)};
	f02->SetParameter(0,10);
	f02->SetParameter(1,15);
	f02->SetParameter(2,1.5);
	f02->Draw();
}
	
