/* 
TGraph : A TGraph is an object made of two arrays X and Y with npoints each. 
The TGraph painting is done by TGraphPainter class. 
The options to draw a graph are described in TGraphPainter class.
*/

// https://root.cern.ch/doc/master/classTGraph.html
// TGraphPointer : Implements all graphs' drawing's options.
// https://root.cern.ch/doc/master/classTGraphPainter.html

void TGraph_01()
{
   int n {20};
   double x[n], y[n]; // allocate 2n doubles
   
   for (int i{};i<n;++i) // populate 2n doubles
   { 
     x[i] = i*0.1;
     y[i] = 10*sin(x[i]+0.2);
   }
   auto g {new TGraph(n,x,y)};
   
   // default title "Graph" / Observe the structured string!
   g->SetTitle("Graph: 10*sin(x+0.2);X title;Y title"); 
	
   // default name "Graph"
   g->SetName("GraphNoOne");

   // g->Draw("AC*");
   g->Draw("AL*");
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
