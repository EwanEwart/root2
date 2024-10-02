void ex_tgraph_errors()
{
	// canvas
	//
   auto c2 { new TCanvas{"c2","A Simple Graph with error bars",900,100,700,500 } };
   // auto c1 = new TCanvas("c1","A Simple Graph with error bars",1);
   c2->SetFillColor(42); // use TColor_01.C, colourTable() to determine index of colour, beige
   c2->SetGrid();
   c2->GetFrame()->SetFillColor(21);   // refer to TColor_01.C, colourTable(), grey
   c2->GetFrame()->SetBorderSize(12);
	
	// data
	//
   Int_t const n = 10;
   Double_t x[n]  = {-0.22,0.05,0.25,0.35,0.50,0.61,0.70,0.85,0.89,0.95};
   Double_t y[n]  = { 1.00,2.90,5.60,7.40,9.00,9.60,8.70,6.30,4.50,1.00};
   Double_t ex[n] = { 0.05,0.10,0.07,0.07,0.04,0.05,0.06,0.07,0.08,0.05};
   Double_t ey[n] = { 0.80,0.70,0.60,0.50,0.40,0.40,0.50,0.60,0.70,0.80};

	// graph errors
	//
   auto gr = new TGraphErrors(n,x,y,ex,ey); // passing data
   gr->SetTitle("EE TGraphErrors Example");
   gr->SetMarkerColor(4); // use TColor_01.C, colourTable() to determine index of colour, dark blue
   gr->SetMarkerStyle(21); // TAttMarker_01.png / TAttMarker_02.png, solid square
	gr->SetLineColor(kBlue);  // TColor_01.C, colourWheel() to determine index of colour
   gr->Draw("ALP");
	// A : the axis should be drawn
	// L : draw the graph as a simple line
	// P : The current marker is plotted at each point 
	// refer to class TGraphPainter
}
