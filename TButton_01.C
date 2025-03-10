#include<TROOT.h> // gROOT
#include<TSystem.h> // gRootDir
#include<TApplication.h>
#include<TButton.h>
#include<TDialogCanvas.h>
#include<TGraph.h>

using std::string;

void TButton_01()
{
   // example of a TDialogCanvas canvas with a few buttons
   float const x1 {.05};
   float const y1 {.80};
   float const x2 {.45};
   float const y2 {.88};

   float const dx {.50};
   float const dy {.15};

   // Create a TDialogueCanvas, which is not editabel by default
   auto aTDialogCanvas
   {
      new TDialogCanvas
      (
         "aTDialogCanvas"  // name
         , "n TButton" // title / caption
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
         "34 + 56 = ... "   // title / caption
         , "34+56"   // method / action , executed when pressed
         , x1       // x1 x bottom left  corner of pad in NDC [0..1] fXlowNDC
         , y1       // y1 y bottom left  corner of pad in NDC [0..1] fYlowNDC
         , x2       // x2 x upper  right corner of pad in NDC [0..1] fXUpNDC
         , y2       // y2 y upper  right corner of pad in NDC [0..1] fYUpNDC
      )
   };
   aTButton_Addition->Draw();
   
   // Create second button. 
   auto aTButton_extreme_C_01_07
   {
      new TButton
      (
         ".x extreme_C_01_07.C" // title / caption
         , ".x extreme_C_01_07.C" // method / action , executed when pressed
         , x1    // x1 x bottom left  corner of pad in NDC [0..1] fXlowNDC
         , y1-dy // y1 y bottom left  corner of pad in NDC [0..1] fYlowNDC
         , x2    // x2 x upper  right corner of pad in NDC [0..1] fXUpNDC
         , y2-dy // y2 y upper  right corner of pad in NDC [0..1] fYUpNDC
      )
   };
   aTButton_extreme_C_01_07->Draw();
   
   // Create third button. 
   // Clicking on this button will create a new canvas
   auto aTButton_NewCanvas
   {
      new TButton
      (
         "new TCanvas(\"c2\",\"c2\")" // title / caption
         , "auto c2 = new TCanvas(\"c2\",\"c2\")" // method / action , executed when pressed
         , x1+dx    // left bottom 
         , y1       // left bottom
         , x2+dx    // top right
         , y2       // top right
      )
   };
   aTButton_NewCanvas->Draw();

   // Create forth button. 
   // Clicking on this button will create a new canvas
   auto aTButton_TF1_01
   {
      new TButton
      (
         ".x TF1_01.C" // title / caption
         , ".x TF1_01.C" // method / action , executed when pressed
         , x1+dx          // left bottom 
         , y1-dy          // left bottom
         , x2+dx          // top right
         , y2-dy          // top right
      )
   };
   aTButton_TF1_01->Draw();

   // Create fifth button.
   // Clicking on this button will invoke the browser
   auto aTButton_ObjBrowser
   {
       new TButton
       (
           "Invoke ROOT Object Browser: auto br = new TBrowser(\"br\")" // title / caption
           , "auto br = new TBrowser(\"br\")" // method / action , executed when pressed
           , x1       // Double_t x1 lower left
           , y1-2*dy  // Double_t y1 lower left
           , x2+dx    // Double_t x2 upper right
           , y2-2*dy  // Double_t y2 upper right
      )
   };
   aTButton_ObjBrowser->SetFillColor(42);
   aTButton_ObjBrowser->Draw();

   // Create sixth button w/o name.
   // Instead a graph is drawn inside the button
   // Clicking on this button will invoke the macro
   // $ROOTSYS/tutorials/graphs/graph.C
   auto aTButton_with_TGraph
   {
      new TButton
      (
         ".x graph.C" // button caption
         // , (TString(".x ") + gRootDir + "/" + "tutorials/graphs/graph.C") // method / action
         , (TString(".x ") + gROOT->GetTutorialDir() + "/" + "graphs/graph.C") // method / action
         , x1
         , y1-4*dy
         , x2+dx
         , y2-3*dy
      )
   };
   aTButton_with_TGraph->SetFillColor(42);
   aTButton_with_TGraph->Draw();
   aTButton_with_TGraph->SetEditable(kTRUE); // consome edit events
   aTButton_with_TGraph->cd();


   // TGraph
   Double_t x[8] = {0.08, 0.21, 0.34, 0.48, 0.61, 0.70, 0.81, 0.92};
   Double_t y[8] = {0.20, 0.65, 0.40, 0.34, 0.24, 0.43, 0.75, 0.52};

   auto nx{sizeof(x) / sizeof(Double_t)};
   auto ny{sizeof(y) / sizeof(Double_t)};
   auto n{nx<ny?nx:ny};

   auto graph{ new TGraph(n, x, y)};
   graph->SetMarkerColor(kBlue);
   graph->SetMarkerStyle(kFullTriangleDown);
   graph->SetLineColor(kRed);
   graph->SetLineWidth(2);
   graph->Draw("LP"); // ALP => crash / refer to doc_Draw.md

   aTButton_with_TGraph->SetEditable(kFALSE); // consume button events instead of TGraph events
   
   aTDialogCanvas->cd(); // cd to TDialogCanvas & draw TButton onto it
   
   // Create sixth button w/o name.
   auto aTButton_Quit
   {
      new TButton
      (
         "Quit" // title / caption
         , ".q" // method / action , executed when pressed
         , x1+dx
         , y1-5*dy
         , x2+dx
         , y2-5*dy
      )
   };
   aTButton_Quit->Draw();
}
