/*

https://root.cern/manual/creating_a_user_application/

Example using ROOT prompt
=========================

You can use TRint to create an environment
providing an interface
- to the windows manager and
- window's event loop
via the inheritance of TApplication.

In addition TRint provides interactive access
to the Cling C++ interpreter
via the command line.

On Linux and MacOS compile and run the app_04.cxx file as following :

g++ app_04.cxx $(root-config --glibs --cflags --libs) -o app_04

The equivalent command on Windows is:

> cl -nologo -MD -GR -EHsc app_04.cxx -I %ROOTSYS%\include /link -LIBPATH:%ROOTSYS%\lib libCore.lib libGpad.lib libHist.lib
> app_04

Note

You can use root-config --cflags
to be sure to use the correct compiler flags (Debug vs Release)

Rint is the (R)OOT (Int)eractive Interface.
It allows interactive access
to the ROOT system via the C++ interpreter.

*/

#include <TRint.h>

#include <TCanvas.h>
#include <TF1.h>
#include <TVector.h>
#include <TMath.h>

int main(int argc, char *argv[])
{
   /*
   TRint
   (
      char const *   appClassName,
      Int_t *        argc,
      char  **       argv,
      void  *        options           =  nullptr,
      Int_t          numOptions        =  0,
      Bool_t         noLogo            =  kFALSE,
      Bool_t         exitOnUnknownArgs =  kFALSE
   )
   Creates an application environment
   - executes the code following
   - provides a ROOT prompt
   */
   TRint app("app", &argc, argv); // construct root interactive interface

   Int_t wtopx{400}, wtopy{100}, ww{800 / 2 + 50}, wh{600 / 2 + 50};
   auto c{new TCanvas("c", "Trigonometric Function", wtopx, wtopy, ww, wh)};

   Int_t factor {5};
   auto f1{new TF1("f1", "sin(x)/x", factor * -TMath::Pi(), factor * TMath::Pi())};
   f1->SetLineColor(kBlue + 1);
   f1->SetTitle("sin(x)/x;x;sin(x)/x");
   f1->Draw();

   c->Modified();
   c->Update();

   app.Run();

   return 0;
}
