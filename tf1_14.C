// TF1, TFormula

void tf1_14()
{
	auto fcos = new TF1 ("fcos", "[0]*cos(x)", 0., 10.);
	fcos->SetParNames( "cos");
	fcos->SetParameter( 0, 1.1);
 
	auto fsin = new TF1 ("fsin", "[0]*sin(x)", 0., 10.);
	fsin->SetParNames( "sin");
	fsin->SetParameter( 0, 2.1);
 
	auto fsincos = new TF1 ("fsc", "fcos+fsin");
 
	auto fs2 = new TF1 ("fs2", "fsc+fsc");

	// fcos->Draw();
	// fsin->Draw();
	// fsincos->Draw();
	fs2->Draw();

}
/*
TF1 objects can reference other TF1 objects
of type A or B defined above.(??
This excludes CLing or compiled functions.
However, there is a restriction.
A function cannot reference a basic function
if the basic function is a polynomial polN.
*/ 
