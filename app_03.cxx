/*
https://root.cern/manual/creating_a_user_application/

Interactive example displaying a canvas
=======================================

Use TApplication
to display the output on a screen.

*TApplication* creates a *ROOT application environment*
that provides an *interface*
- to the windowing system event loops and
- event handlers.

To run the canvas as a *standalone application*
you must create a *TApplication* object.

Calling the Run() method starts the event loop.

On Linux and MacOS compile and run the app_03.cxx file as following :

g++ app_03.cxx $(root-config --glibs --cflags --libs) -o app_03

The equivalent command on Windows is:

> cl -nologo -MD -GR -EHsc app_03.cxx -I %ROOTSYS%\include /link -LIBPATH:%ROOTSYS%\lib libCore.lib libGpad.lib libHist.lib
> app_03



Note

You can use root-config --cflags
to be sure to use the correct compiler flags (Debug vs Release)

*/

#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRootCanvas.h>
#include <TMath.h>

int main(int argc, char *argv[])
{
   /*
   TApplication::TApplication
   ( 	char const * appClassName,
      Int_t *  	 argc,
      char **  	 argv,
      void *  	    options = nullptr,
      Int_t  	    numOptions = 0
   )
   */
   TApplication app("app", &argc, argv);

   Int_t wtopx{400}, wtopy{100}, ww = 800 / 2 + 50, wh = 600 / 2 + 50;
   auto c{new TCanvas("c", "Trigonometric Function", wtopx, wtopy, ww, wh)};

   auto f1{new TF1("f1", "sin(x)", 2 * -TMath::Pi(), 2 * TMath::Pi())};
   f1->SetLineColor(kBlue + 1);
   f1->SetTitle("sin;x;sin(x)"); // title;x-lable;y-lable
   f1->Draw();

   c->Modified();
   c->Update();

   auto root_canvas{dynamic_cast<TRootCanvas *>(c->GetCanvasImp())};
   auto success{
       root_canvas->Connect(
           "CloseWindow()", // signal
           "TApplication",  // receiver class
           gApplication,    // receiver
           "Terminate()"    // slot
           )};
   if (success)
   {
      std::cout << "app_5 ✔ TRootCanvas conected ✔ " << std::endl;
   }
   else
   {
      std::cerr << "app_5 χ TRootCanvas NOT conected. χ " << std::endl;
   }

   app.Run(); // start event loop

   return 0;
}
