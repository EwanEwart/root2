void TButton_01()
{
//   example of a aTDialogCanvas canvas with a few buttons
 
   auto aTDialogCanvas { new TDialogCanvas("aTDialogCanvas","4 x TButton",300,300) };
 
// Create first button. Clicking on this button will execute 34+56
   auto aTButton_Add { new TButton("btn 34+56","34+56",.05,.8,.45,.88) };
   aTButton_Add->Draw();
 
// Create second button. Clicking on this button will create a new canvas
   auto aTButton_NewCanvas { new TButton("New Canvas","c2 = new TCanvas(\"c2\")",.55,.8,.95,.88) };
   aTButton_NewCanvas->Draw();
 
// Create third button. 
// Clicking on this button will invoke the browser
   auto aTButton_ObjBrowser 
   {  
      /* 
      TButton 
      (
           char const * title 
         , char const * method
         , Double_t x1
         , Double_t y1
         , Double_t x2
         , Double_t y2
      )
      */
      new TButton
      (
         "Invoke ROOT Object Browser"  // char const * title 
         ,"br = new TBrowser(\"br\")"  // char const * method
         ,0.05 // Double_t x1
         ,0.54 // Double_t y1
         ,0.95 // Double_t x2
         ,0.64 // Double_t y2
      ) 
   };
   aTButton_ObjBrowser->SetFillColor(42);
   aTButton_ObjBrowser->Draw();
 
// Create last button with no name. 
// Instead a graph is drawn inside the button
// Clicking on this button will invoke the macro 
// $ROOTSYS/tutorials/graphs/graph.C
   auto button { new TButton("",".x tutorials/graphs/graph.C",0.15,0.15,0.85,0.38) };
   button->SetFillColor(42);
   button->Draw();
   button->SetEditable(kTRUE);
   button->cd();
 
   // TGraph
   Double_t x[8] = { 0.08 , 0.21 , 0.34 , 0.48 , 0.61 , 0.70 , 0.81 , 0.92 } ;
   Double_t y[8] = { 0.20 , 0.65 , 0.40 , 0.34 , 0.24 , 0.43 , 0.75 , 0.52 } ;
   
   auto nx { sizeof(x)/sizeof(Double_t) };
   auto ny { sizeof(y)/sizeof(Double_t) };
   auto n  { min(nx,ny) };
   
   auto graph { new TGraph(n,x,y) };
   
   graph->SetMarkerColor(kBlue);
   graph->SetMarkerStyle(kFullTriangleDown);
   graph->SetLineColor(kRed);
   graph->SetLineWidth(2);

   graph->Draw("LP");
 
   aTDialogCanvas->cd();
}
