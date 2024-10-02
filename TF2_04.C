// TF2, TParameter
void tf2_04()
{
	auto f04 {new TF2("f04","gaus(x, [0..2]) + expo(y, [3..4])")};
	f04->SetParameters(3,7,5,2,-.3);
	f04->Draw();
}

