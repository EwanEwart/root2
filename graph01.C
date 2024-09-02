// TGraph
// https://root.cern/doc/master/classTGraph.html
void graph01()
{
   int n {20};
   double x[n], y[n]; // allocate 2n doubles
   for (int i{};i<n;i++) { // populate 2n doubles
     x[i] = i*0.1;
     y[i] = 10*sin(x[i]+0.2);
   }
   auto g {new TGraph(n,x,y)};
   g->SetTitle("Graph title;X title;Y title"); // Observe the structured string!
	g->SetName("10*sin(x[i]+0.2"); // ??
   g->Draw("AC*");
	// A : Produce a new plot with Axis around the graph
	// C : A smooth curve is drawn
	// * : A Star is plotted at each point
	// refer to TGraphPainter
}
