void ex_first_ROOT_macro() {

	// first ROOT macro

	gROOT->SetStyle("Plain");
	// set plain TStyle

	gStyle->SetOptStat(111111);
	// draw statistics on plots
	// (0) for no output

	gStyle->SetOptFit(1111); 
	// draw fit results on plot
	// (0) for no ouput 

	gStyle->SetPalette(57);     
	// set colour map

	gStyle->SetOptTitle(0);   
	// suppress title box

	// auto c1 = new TCanvas ( "c1","First ROOT Macro",200,200,400,300 );
	auto c1 { new TCanvas{ "c1","A Simple Graph with error bars",900,100,700,500 } };

	// create a canvas, specify position and size in pixels

	c1->Divide(2,2);
	//set subdivisions, called pads

	c1->cd(1);
	//change to pad 1 of canvas c1

	// ... empty convas & pads
	// auto p1 {new TF1{"p1","Pad no. 1","-x",100,100,200,200}};
	// p1->Draw();
}

