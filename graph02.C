// TGraph
// https://root.cern/doc/master/classTGraph.html
// Default x points
void graph02()
{
	double y [] {3,8,1,10,5,7,7,7}; // C array
	size_t n {sizeof(y)/sizeof(double)}; // => n x values 1,2,3,...,n
	auto g {new TGraph(n,y)}; // <-- n   <-- y  automatic / x coordinates: 1,2,...
	g->SetTitle("A Graph with default x coordinates;x : auto generated values;y : static array data");
	g->Draw();
	// g->Draw("AL*"); // alternative
	// A : Produce a new plot with Axis around the graph 
	// L : A simple polyline is drawn 
	// * : A Star is plotted at each point
	// Refer to TGraphPainter
}

