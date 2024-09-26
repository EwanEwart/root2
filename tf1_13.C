// TF1, TFormula, Lambda

/*
4 - A general C function with parameters

Consider the macro tf1_13.C
*/

// Macro tf1_13.C

// C-fcn of type : Double_t(*fcn)(Double_t*, Double_t*)
// double aFunction(double *x, double *p)
Double_t aFunction(Double_t *x, Double_t *p)
{
	auto x0 {x[0]};
   Double_t f = TMath::Abs( p[0] * sin(p[1] * x0) / x0 );
	//cout<<x[0]<<endl;
	//cout<<x[1]<<endl;
	//cout<<x[2]<<endl;
	//cout<<"--------"<<endl;
   return f;
}

// entry point
void tf1_13()
{
   auto f1
	{  // Constructor using a pointer to *a real function* instead of a *formula*.
		new TF1
		(
			  "aFunction"  // char const* name
			, aFunction    // Double_t(*fcn)(Double_t*, Double_t*) (function pointer)
			,  0.0         // Double_t xmin = 0
			, 10.0         // Double_t xmax = 1
			, 2	         // Int_t npar = 0
			// Int_t ndim=1
			// EAddToList addToGlobList=EAddToList::kDefault
		)
	};
   f1->SetParameters(1,1);
   f1->SetParNames("constant","coefficient");
   f1->Draw();
}

void tf1_13_fit()
{
	/*
	histograms with one float per channel.
	Maximum precision 7 digits,
	maximum integer bin content = +/- 16 777 216 (***)
	*/
	// TH1F (char const *name, char const *title, Int_t nbinsx, Double_t xlow, Double_t xup)
   auto h1
	{
		new TH1F
		(
			  "h1"   // char const* name
			, "test" // char const* title
			, 100 	// Int_t nbinsx
			,   0.0  // Double_t xmin
			,  10.0  // Double_t  xmax
		)
	} ;

   // Fill histogram following distribution in function fname.
   h1->FillRandom
   (
      "aFunction" // fname	: Function name used for filling the histogram 
      ,20000      // ntimes	: number of times the histogram is filled
      // rng	: (optional) (R)andom (N)umber (G)enerator used to sample
   );

   auto f2 { (TF1 *)gROOT->GetFunction("aFunction") };
   f2->SetParameters(800,2);
   
   h1->Fit("aFunction");
}

/*
In an interactive session you can do:
Root > .L tf1_13.C
Root > tf1_13();
Root > tf1_13_fit();
*/
