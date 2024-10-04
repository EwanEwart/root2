/*
TGraph : A TGraph is an object made of two arrays X and Y with npoints each. 
The TGraph painting is done by TGraphPainter class. 
The options to draw a graph are described in TGraphPainter class.
*/

// https://root.cern.ch/doc/master/classTGraph.html
// TGraphPointer : Implements all graphs' drawing's options.
// https://root.cern.ch/doc/master/classTGraphPainter.html

// Default x points
void TGraph_02()
{
      /*
   ////////////////////////////////////////////////////////////////////////////////
/// Create a new canvas.
///
/// \param[in] name         canvas name
/// \param[in] title        canvas title
/// \param[in] wtopx,wtopy  are the pixel coordinates of the top left corner of
///                         the canvas (if wtopx < 0) the menubar is not shown)
/// \param[in] ww           is the window size in pixels along X
/// \param[in] wh           is the window size in pixels along Y
///
/// If "name" starts with "gl" the canvas is ready to receive GL output.
 
TCanvas::TCanvas
( 
      char const* name
   ,  char const* title
   ,  Int_t       wtopx
   ,  Int_t       wtopy
   ,  Int_t       ww
   ,  Int_t       wh
)
: TPad(), fDoubleBuffer(0)
{
   fPainter = nullptr;
   fUseGL = gStyle->GetCanvasPreferGL();
 
   Constructor(name, title, wtopx, wtopy, ww, wh);
}
   */
   auto 
   c1 
   { 
      new TCanvas
      (
            "c1"  // canvas name
         ,  "canvas title of canvas \"c1\"" // canvas title
         ,   200  // wtopx : are the pixel coordinates of the top left corner of the canvas (if wtopx < 0) the menubar is not shown)
         ,   100  // wtopy : are the pixel coordinates of the top left corner of the canvas (if wtopx < 0) the menubar is not shown)
         ,   600  // ww    : (w)indow (w)idth  : is the window size in pixels along X
         ,   400  // wh    : (w)indow (h)eight :is the window size in pixels along Y
      ) 
   };
   c1->SetFillColor(kOrange-9); // TColor_01.C, colourWheel() to determine index of colour1.C, colourWheel() to determine index of colour
   c1->SetFillColor(42); // use TColor_01.C, colourTable() to determine index of colour
   c1->SetGrid();

   // y : the frequency of lottery numbers: up to 2024-10-02
	double y [] 
   {
   //         1  2  3  4  5  6  7  8  9 10
   /*   */    0, 2, 1, 2, 4, 2, 0, 1, 2, 2, // 10
   /* 1 */    3, 0, 0, 2, 0, 2, 1, 3, 0, 0, // 20
   /* 2 */    1, 1, 2, 1, 2, 3, 3, 3, 0, 1, // 30
   /* 3 */    1, 1, 2, 0, 0, 0, 0, 0, 0, 1, // 40
   /* 4 */    1, 0, 2, 1, 1, 3, 0, 2, 1  
   };
   double ys []  // super no.
   {
   // 1  2  3  4  5  6  7  8  9 10
      1, 2, 0, 0, 1, 1, 0, 2, 3, 0
   };
	size_t n {sizeof(y)/sizeof(double)}; // => n x values 1,2,3,...,n

   // ctor : TGraph(Int_t n, Double_t const *y, Double_t start=0., Double_t step=1.);
	auto g 
   {
      new TGraph
      (
            n  // no. of x-data: here calculated
         ,  y  // y-data: array of doubles
         ,  1  // start x-axis: 1,2,...
               // step=1
      )
   }; 
   
   // <-- n   <-- y  automatic / x coordinates: 1,2,...
	g->SetTitle("A Graph with default x coordinates;x : auto generated values;y : static array data");
   
   /* marker
      - colour
      - size
      - style
   */
   
   g->SetMarkerColor(kRed);
   g->SetMarkerColor(kGreen);
   g->SetMarkerColor(kBlue);
   g->SetMarkerColor(kOrange+1);
   
   // https://root.cern.ch/doc/master/classTAttMarker.html   
   // g->SetMarkerStyle(kPlus);
   // g->SetMarkerStyle(23);
   // g->SetMarkerStyle(kDot);
   // g->SetMarkerStyle(kPlus);
   // g->SetMarkerStyle(kStar);
   // g->SetMarkerStyle(kCircle);
   // g->SetMarkerStyle(kMultiply);
   // g->SetMarkerStyle(kFullDotSmall);
   // g->SetMarkerStyle(kFullDotMedium);
   g->SetMarkerSize(1);
   g->SetMarkerSize(1.5);
   g->SetMarkerStyle(EMarkerStyle::kFullDotLarge);
   // g->SetMarkerStyle(kFullCircle);
   // g->SetMarkerStyle(kFullSquare);
   // g->SetMarkerStyle(kFullTriangleDown);
   // g->SetMarkerStyle(kFullTriangleUp);
   // ... etc ...
   
   g->Draw();
	// g->Draw("AL*"); // alternative
	// g->Draw("AC*"); // alternative
	// A : Produce a new plot with Axis around the graph 
	// L : A simple polyline is drawn 
   // C : smooth, contious
	// * : A Star is plotted at each point
	// Refer to TGraphPainter

   // TCanvas::Update() draws the frame, then it may be changed
   c1->Update();
   c1->GetFrame()->SetFillColor(kOrange-8); // use TColor_01.C, colourTable() to determine index of colour
   c1->GetFrame()->SetBorderSize(2);
   c1->Modified();

}
