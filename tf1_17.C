// TF1

class  MyFunction
{
 public:
   // ...
   double Evaluate(double *x, double *p)
	{
		auto x0=x[0];
      // function implementation:...
		if( x0 != 0 )
			return p[0]*sin(x0)/x0;
		else
			return 0;
   }
};
void tf1_17()
{
   // ...
	auto npar{1};

	// create the user function class
   MyFunction *fptr = new MyFunction();

	// create TF1 class.
   auto f = new TF1("f",fptr,&MyFunction::Evaluate,0,1,npar,"MyFunction","Evaluate");
	f->SetParameter(0,2.0);
	f->Draw();

   // ...
}

/*

6 - A member function with parameters of a general C++ class

A TF1 can be created in this case
from any member function of a class,
which has a signature of ...

- double(double * , double *)

*/



