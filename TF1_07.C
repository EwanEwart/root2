// TF1, TFormula, UDF
// 4. A general C function with parameters

// a C-function
auto aFn(double x){return x+sin(x);};

void tf1_07()
{
	auto f07 
	{	
		new TF1
		(
			  "f07" // name
			, "aFn(x)" // formula : C-UDF
			, -3 // xmin
			,  5 // xmax
		)
	};

	f07->Draw();

	return;
}

