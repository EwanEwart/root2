// TF1, TFormula, UDF
auto aFn(double x){return x+sin(x);};

void tf1_07()
{
	auto f07 {new TF1("f07","aFn(x)",-3,5)};
	f07->Draw();
}

