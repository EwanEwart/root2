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
   auto f1 = new TF1("aFunction",aFunction,0,10,2); // 2 == 2 parameters
   f1->SetParameters(2,1);
   //f1->SetParNames("constant","coefficient");
   f1->Draw();
}
void tf1_13_fit()
{
   auto h1 = new TH1F("h1","test",100,0,10);
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

