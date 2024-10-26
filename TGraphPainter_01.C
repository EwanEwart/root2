void TGraphPainter_01()
{


   // https://root.cern.ch/doc/master/Rtypes_8h_source.html
   // https://root.cern.ch/doc/master/Rtypes_8h.html
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

   Int_t const n {20};
   Double_t x[n], y[n];
   for (Int_t i = 0; i < n; ++i)
   {
      x[i] = i * 0.1;
      y[i] = 10 * sin(x[i] + 0.2);
   }

   auto gr = new TGraph(n, x, y);
   gr->SetLineColor(2); // use TColor_01.C, colourTable() to determine index of colour
   gr->SetLineWidth(4);

   // https://root.cern.ch/doc/master/classTAttMarker.html
   gr->SetMarkerColor(4); // use TColor_01.C, colourTable() to determine index of colour
   gr->SetMarkerSize(1.5);
   gr->SetMarkerStyle(21); // TAttMarker_01.png / TAttMarker_02.png, solid square
   
   // gr->SetTitle("Option ACP example");
   // gr->GetXaxis()->SetTitle("X title");
   // gr->GetYaxis()->SetTitle("Y title");
   
   gr->SetTitle("Option ACP example");
   gr->GetXaxis()->SetTitle("X title");
   gr->GetYaxis()->SetTitle("Y title");
   
   gr->Draw("ACP");
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

   // TCanvas::Update() draws the frame, then it may be changed
   c1->Update();
   c1->GetFrame()->SetFillColor(21); // use TColor_01.C, colourTable() to determine index of colour
   c1->GetFrame()->SetBorderSize(2);
   c1->Modified();
}
