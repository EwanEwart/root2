// TGraph : A TGraph is an object made of two arrays X and Y with npoints each. 
// https://root.cern.ch/doc/master/classTGraph.html
// TGraphPointer : Implements all graphs' drawing's options.
// https://root.cern.ch/doc/master/classTGraphPainter.html

// Default x points
void graph02()
{
   // the frequency of lottery numbers: up to 2024-10-02
	double y [] 
   {
   //  1  2  3  4  5  6  7  8  9 10
      0,  0, 0, 2, 1, 1, 0, 0, 1, 0,
      2,  0, 0, 0, 0, 1, 1, 2, 0, 0,
      0,  0, 1, 0, 0, 2, 1, 2, 0, 1,
      0,  0, 1, 0, 0, 0, 0, 0, 0, 1,
      1,  0, 1, 0, 0, 2, 0, 0, 0, 0
   };
   double ys [] 
   {
   // 1  2  3  4  5  6  7  8  9 10
      1, 0, 0, 0, 0, 1, 0, 0, 2, 0
   };
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
