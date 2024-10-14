void TButton_01()
{
   //   example of a aTDialogCanvas canvas with a few buttons
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

   // btn 01
   // Create first button. 
   // Clicking on this button will calculate 34+56
   auto aTButton_Addition
   {
      new TButton
      (
         "btn 34+56" // title / name
         , "34+56" // method / action , executed when pressed
         , .05    // x1 x bottom left  corner of pad in NDC [0..1] fXlowNDC
         , .80    // y1 y bottom left  corner of pad in NDC [0..1] fYlowNDC
         , .45    // x2 x upper  right corner of pad in NDC [0..1] fXUpNDC
         , .88    // y2 y upper  right corner of pad in NDC [0..1] fYUpNDC
      )
   };
   aTButton_Addition->Draw();

   // btn 02
   auto aTButton_extreme_C_01_07
   {
      new TButton
      (
         "btn C Extreme Macro" // title / name
         , ".x extreme_C_01_07.C"
         // , ".x TF1_02.C" // crash
         , .05    // x1 x bottom left  corner of pad in NDC [0..1] fXlowNDC
         , .80-dy // y1 y bottom left  corner of pad in NDC [0..1] fYlowNDC
         , .45    // x2 x upper  right corner of pad in NDC [0..1] fXUpNDC
         , .88-dy // y2 y upper  right corner of pad in NDC [0..1] fYUpNDC
      )
   };
   aTButton_extreme_C_01_07->Draw();

   // btn 03
   // Create second button. 
   // Clicking on this button will create a new canvas
   auto aTButton_NewCanvas
   {
      new TButton
      (
         "New Canvas"
         , "c2 = new TCanvas(\"c2\")"
         , .05+dx    // left bottom 
         , .80       // left bottom
         , .45+dx    // top right
         , .88       // top right
      )
   };
   aTButton_NewCanvas->Draw();

   // btn 04
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

   // btn 05
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
      )};
   button->SetFillColor(42);
   button->Draw();
   button->SetEditable(kTRUE);
   button->cd();

   // TGraph
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

   aTDialogCanvas->cd();
}
