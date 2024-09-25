// TF1, TFormular, a Functor, a Function Object
// 5 - A general C++ function object (functor) with parameters
//

class AFunctionObject
{
public:
   // use constructor to customise your function object
 
   double operator() (double *x, double *p)
	{
      // function implementation using class data members
		double x0 = x[0];
		return TMath::Abs( p[0] * sin(p[1] * x0) / x0 );
   }
};

// entry point
void tf1_15()
{
// ....
	int npar {2};
	AFunctionObject fobj;
   // create TF1 class using "function object"
	auto f15 { new TF1("f15",fobj,-10.0,10.0,npar) };
	f15->SetParameters(2.0,1.0);
   f15->SetParNames("constant","coefficient");
	f15->Draw();
// .....
}

/*
5 - A general C++ function object (functor) with parameters

A TF1 can be created from any C++ class
implementing the operator()(double *x, double *p).
The advantage of the function object is
that it can have a state and reference

*/
