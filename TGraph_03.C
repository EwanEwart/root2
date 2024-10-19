#include<TGraph.h>
/* 
TGraph : A TGraph is an object made of two arrays X and Y with npoints each. 
The TGraph painting is done by the TGraphPainter class. 
The options to draw a graph are described in TGraphPainter class.
*/ 

// https://root.cern.ch/doc/master/classTGraph.html
// TGraphPointer : Implements all graphs' drawing's options.
// https://root.cern.ch/doc/master/classTGraphPainter.html

// Read x-y-data from file
void TGraph_03()
{
	auto g 
   {
      //  TGraph(const char *filename, const char *format="%lg %lg", Option_t *option="");
      new TGraph
      (
         "tgraph04.data"   // filename
      ,  "%lg %lg"         // format
      ,  " "               // option
      )
   };
	g->SetTitle("tgraph04.data;x-coord;y-coord");
   
   g->SetMarkerStyle(kFullSquare);
   g->SetMarkerColor(kRed);
   g->SetMarkerSize(1.5);

   g->SetLineColor(kBlue);
   g->SetLineWidth(2);
   
   // g->Draw();
	// g->Draw("AC*");
	g->Draw("ALPRXRY"); // alternative
	// g->Draw("AL*"); // alternative
	// A : Produce a new plot with Axis around the graph 
	// L : A simple polyline is drawn 
	// C : A smooth Curve is drawn 
	// * : A Star is plotted at each point
	// Refer to TGraphPainter
   
}
