/*
https://root.cern/manual/creating_a_user_application/


Creating a user application with ROOT
On this page

    The simple ROOT macro
    Batch example generating a PDF file
    Interactive example displaying a canvas
    Example using ROOT prompt

Starting from a simple ROOT macro creating and displaying a canvas, this section shows how to create a standalone user application based on ROOT libraries.

Three different kind of standalone user applications are presented:

    Batch example generating a PDF file
    Interactive example displaying a canvas
    Example using ROOT prompt

A simple ROOT macro
===================

The following code can be executed interactively at the ROOT prompt:

*/

#include <TCanvas.h>
#include <TF1.h>
#include <TMath.h>

void app_01()
{
   // c1 default canvas
   auto c1{new TCanvas("c1", "Trigonometric Functions (c1)", 400, 100, 800 * 2 / 3, 600 * 2 / 3)};
   // c2 default canvas
   double const dx{150.0}, dy{100.0};
   auto c2{new TCanvas("c2", "Trigonometric Functions (c2)", 400+dx, 100+dy, 800 * 2 / 3, 600 * 2 / 3)};
   // now, c1 default canvas
   c1->cd();

   auto f1{new TF1("f1", "sin(x)", 0., TMath::Pi() * 2.0)};

   f1->SetTitle("f(x)=sin(x);x; sin(x)"); // "title ; x-lable ; y-lable"
   f1->SetLineColor(kRed + 1);
   f1->SetLineStyle(1);
   f1->SetLineWidth(1);

   f1->Draw();
}
