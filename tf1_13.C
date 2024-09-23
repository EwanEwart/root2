// TF1, TFormula, Lambda

/*
4 - A general C function with parameters

Consider the macro tf1_13.C below:
*/

// Macro tf1_13.C
Double_t aFunction(Double_t *x, Double_t *par)
{
	auto x0 {x[0]};
   Double_t f = TMath::Abs( par[0] * sin(par[1] * x0) / x0 );
	//cout<<x[0]<<endl;
	//cout<<x[1]<<endl;
	//cout<<x[2]<<endl;
	//cout<<"--------"<<endl;
   return f;
}

void tf1_13()
{
   auto f1
	{  // Constructor using a pointer to *a real function* instead of a *formula*.
		new TF1
		(
			  "aFunction" // char const* name
			, aFunction // Double_t(*fcn)(Double_t*, Double_t*)
			,  0.0 // Double_t xmin = 0
			, 10.0 // Double_t xmax = 1
			, 2	// Int_t npar = 0
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
			  "h1" // char const* name
			, "test" // char const* title
			, 100 	// Int_t nbinsx
			,   0.0 // Double_t xmin
			,  10.0// Double_t  xmax
		)
	} ;
   h1->FillRandom("aFunction",20000);
   TF1 *f1 = (TF1 *)gROOT->GetFunction("aFunction");
   f1->SetParameters(800,1);
   h1->Fit("aFunction");
}

/*
In an interactive session you can do:
Root > .L tf1_13.C
Root > tf1_13();
Root > tf1_13_fit();
*/

