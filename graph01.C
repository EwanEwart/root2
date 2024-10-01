// TGraph
// https://root.cern/doc/master/classTGraph.html
void graph01()
{
   int n {20};
   double x[n], y[n]; // allocate 2n doubles
   for (int i{};i<n;++i) { // populate 2n doubles
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
	// A : Produce a new plot with an Axis around the graph
	// C : A smooth curve is drawn(, continious)
   // L : a poly-line is drawn
	// * : A Star is plotted at each point
	// refer to TGraphPainter
}
