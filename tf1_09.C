// TF1, TFormula, parameter
void tf1_09()
{
	auto f09 { new TF1("f09","[0]*x*sin([1]*x)",-3,3)};
	f09->SetParameters(10,2); // two parameters in this order
	f09->SetParNames("p1","p2"); // two parameters in this order
	f09->Draw(); // => p1 = 10 && p2 = 2
}

