void TButton_01()
{
   //   example of a TDialogCanvas canvas with a few buttons
   float dx {.50};
   float dy {.16};

   auto aTDialogCanvas
   {
      new TDialogCanvas
      (
         "aTDialogCanvas"  // name
         , "4 x TButton" // dialogue caption
         , 500 // width
         , 300 // height
      )
   };

   // Create first button. 
   // Clicking on this button will calculate 34+56
   auto aTButton_Addition
   {
      new TButton
      (
           "aTButton_Addition"   // title / name
         , "34+56"   // method / action , executed when pressed
         , .05       // x1 x bottom left  corner of pad in NDC [0..1] fXlowNDC
         , .80       // y1 y bottom left  corner of pad in NDC [0..1] fYlowNDC
         , .45       // x2 x upper  right corner of pad in NDC [0..1] fXUpNDC
         , .88       // y2 y upper  right corner of pad in NDC [0..1] fYUpNDC
      )
   };
   aTButton_Addition->Draw();

   auto aTButton_extreme_C_01_07
   {
      new TButton
      (
         "C Extreme Macro" // title / name
         , ".x extreme_C_01_07.C"
         , .05    // x1 x bottom left  corner of pad in NDC [0..1] fXlowNDC
         , .80-dy // y1 y bottom left  corner of pad in NDC [0..1] fYlowNDC
         , .45    // x2 x upper  right corner of pad in NDC [0..1] fXUpNDC
         , .88-dy // y2 y upper  right corner of pad in NDC [0..1] fYUpNDC
      )
   };
   aTButton_extreme_C_01_07->Draw();

   // Create second button. 
   // Clicking on this button will create a new canvas
   auto aTButton_NewCanvas
   {
      new TButton
      (
         "New Canvas"
         , "c2 = new TCanvas(\"c2\",\"c2\")"
         , .05+dx    // left bottom 
         , .80       // left bottom
         , .45+dx    // top right
         , .88       // top right
      )
   };
   aTButton_NewCanvas->Draw();

   // Create second button. 
   // Clicking on this button will create a new canvas
   auto aTButton_TF1_02
   {
      new TButton
      (
         "TF1_02"
         , ".x TF1_02.C" // *** crash ***
         , .05+dx          // left bottom 
         , .80-dy          // left bottom
         , .45+dx          // top right
         , .88-dy          // top right
      )
   };
   aTButton_TF1_02->Draw();

   // Create a third button.
   // Clicking on this button will invoke the browser
   auto aTButton_ObjBrowser
   {
       new TButton
       (
           "Invoke ROOT Object Browser" // char const * title
           , "br = new TBrowser(\"br\")" // char const * method
           , 0.05       // Double_t x1 lower left
           , 0.80-2*dy  // Double_t y1 lower left
           , 0.45+dx    // Double_t x2 upper right
           , 0.88-2*dy  // Double_t y2 upper right
      )
   };
   aTButton_ObjBrowser->SetFillColor(42);
   aTButton_ObjBrowser->Draw();

   // Create last button with no name.
   // Instead a graph is drawn inside the button
   // Clicking on this button will invoke the macro
   // $ROOTSYS/tutorials/graphs/graph.C
   auto button
   {
      new TButton
      (
         ""
         , ".x tutorials/graphs/graph.C"
         , 0.05+0.10
         , 0.15
         , 0.45+dx-0.10
         , 0.38
      )
   };
   button->SetFillColor(42);
   button->Draw();
   button->SetEditable(kTRUE);
   button->cd();

   // // TGraph
   Double_t x[8] = {0.08, 0.21, 0.34, 0.48, 0.61, 0.70, 0.81, 0.92};
   Double_t y[8] = {0.20, 0.65, 0.40, 0.34, 0.24, 0.43, 0.75, 0.52};

   auto nx{sizeof(x) / sizeof(Double_t)};
   auto ny{sizeof(y) / sizeof(Double_t)};
   auto n{min(nx, ny)};

   auto graph{new TGraph(n, x, y)};

   graph->SetMarkerColor(kBlue);
   graph->SetMarkerStyle(kFullTriangleDown);
   graph->SetLineColor(kRed);
   graph->SetLineWidth(2);

   graph->Draw("LP");
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

   // aTDialogCanvas->cd();
}
