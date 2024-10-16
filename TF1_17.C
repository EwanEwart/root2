// TF1
// 6 - A "member function" / method with parameters of a general C++ class
/* 
	A TF1 can be created in this case 
	from any member function of a class, 
	which has the signature of (double * , double *) and returning a double.
	double (double, double)
*/

class Class
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

// entry point
void TF1_17()
{
   // ...
	auto npar{1};

	// create the user function class
   Class *p { new Class() };

	// create TF1 class.
	/* ctor TF1 (14/15)
	 	template<class PtrObj , typename MemFn >
		TF1::TF1 	
		( 	
			  char const *  		name
			, PtrObj const &  	p
			, MemFn  				memFn
			, Double_t  			xmin
			, Double_t  			xmax
			, Int_t  				npar
			, char const *  			 
			, char const *  			 
			, EAddToList  		addToGlobList = EAddToList::kDefault 
		) 		
	*/
   auto f 
	{ 
		new TF1
		(
				"f"					// char const *	name
			,  p						// PtrObj const& 	p			// instance / object ptr
			,  &Class::Evaluate	// MemFn  			memFn, 	// member function / class method
			,  -M_PI*2				// Double_t 		xmin
			,   M_PI*2				// Double_t 		xmax
			,  npar					// Int_t				npar
			,  "Class"				// char const * 				// class name
			,  "Evaluate"			// char const * 				// method name
		) 
	};
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
