#include <TRootApplication.h>
#include <TCanvas.h>
#include <TGraphErrors.h>
#include <TFrame.h>

void ex_tgraph_errors()
{
   // canvas
   //
   // auto c1 = new TCanvas("c1","A Simple Graph with error bars",1);
   auto c2{new TCanvas{"c2", "A Simple Graph with error bars", 900, 100, 700, 500}};
   c2->SetFillColor(42); // use TColor_01.C, colourTable() to determine the index of colour, beige
   c2->SetGrid();
   c2->GetFrame()->SetFillColor(21); // refer to TColor_01.C, colourTable(), grey
   c2->GetFrame()->SetBorderSize(12);

   // data
   //
   Int_t const n = 10;
   Double_t x[n] = {-0.22, 0.05, 0.25, 0.35, 0.50, 0.61, 0.70, 0.85, 0.89, 0.95};
   Double_t y[n] = {1.00, 2.90, 5.60, 7.40, 9.00, 9.60, 8.70, 6.30, 4.50, 1.00};
   Double_t ex[n] = {0.05, 0.10, 0.07, 0.07, 0.04, 0.05, 0.06, 0.07, 0.08, 0.05};
   Double_t ey[n] = {0.80, 0.70, 0.60, 0.50, 0.40, 0.40, 0.50, 0.60, 0.70, 0.80};

   // graph errors
   //
   auto gr = new TGraphErrors(n, x, y, ex, ey); // passing data
   gr->SetTitle("EE TGraphErrors Example");
   gr->SetMarkerColor(4);   // use TColor_01.C, colourTable() to determine index of colour, dark blue
   gr->SetMarkerStyle(21);  // TAttMarker_01.png && TAttMarker_02.png, solid square, style ϵ [1,121]
   gr->SetLineColor(kBlue); // TColor_01.C, colourWheel() to determine index of colour
   gr->Draw("ALP");     // refer to class TGraphPainter : https://root.cern/doc/master/classTGraphPainter.html
                            // refer to file doc_Draw.md
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
                            "X+" 	The X-axis is drawn on the top side of the plot.
                            "Y+" 	The Y-axis is drawn on the right side of the plot.
                            "PFC" 	Palette Fill Color: graph's fill color is taken in the current palette.
                            "PLC" 	Palette Line Color: graph's line color is taken in the current palette.
                            "PMC" 	Palette Marker Color: graph's marker color is taken in the current palette.
                            "RX" 	   Reverse the X axis.
                            "RY" 	   Reverse the Y axis.
                            */
   // TCanvas::Update() draws the frame, after which one can change it
   c2->Update();
   c2->GetFrame()->SetFillColor(21);
   c2->GetFrame()->SetBorderSize(12);
   c2->Modified();
}
