// TGraph
// https://root.cern/doc/master/classTGraph.html
// Read x-y-data from file
void graph03()
{
	auto g {new TGraph("tgraph04.data","%lg %lg")};
	g->SetTitle("tgraph04.data;x-coord;y-coord");
	g->Draw("AC*");
	// g->Draw("AL*"); // alternative
	// A : Produce a new plot with Axis around the graph 
	// L : A simple polyline is drawn 
	// C : A smooth Curve is drawn 
	// * : A Star is plotted at each point
	// Refer to TGraphPainter
}

