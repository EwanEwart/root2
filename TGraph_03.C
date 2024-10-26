#include<TCanvas.h>
#include<TGraph.h>
#include<TVector.h>
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
   auto c {new TCanvas("c","TGraph filled from persistent file",400,200,600*3/2+50,400/2*3/2+50)};
   c->SetGrid();
   c->SetEditable();
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
	// refer to class TGraphPainter :
   /*
   Option 	Description
   "A" 	   Produce a new plot with Axis around the graph
   "I" 	   Combine with option 'A' it draws invisible axis
   "L" 	   A simple polyline is drawn
   "F" 	   A fill area is drawn ('CF' draw a smoothed fill area)
   "C" 	   A smooth Curve is drawn
   "*" 	   A Star is plotted at each point
   "P" 	   The current marker is plotted at each point
   "B" 	   A Bar chart is drawn
   "1" 	   When a graph is drawn as a bar chart, this option makes the bars start from the bottom of the pad. By default they start at 0.
   "X+" 	   The X-axis is drawn on the top side of the plot.
   "Y+" 	   The Y-axis is drawn on the right side of the plot.
   "PFC" 	Palette Fill Color: graph's fill color is taken in the current palette.
   "PLC" 	Palette Line Color: graph's line color is taken in the current palette.
   "PMC" 	Palette Marker Color: graph's marker color is taken in the current palette.
   "RX" 	   Reverse the X axis.
   "RY" 	   Reverse the Y axis. 
   
}
