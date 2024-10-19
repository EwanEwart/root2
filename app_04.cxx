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

*/


/* Rint is the (R)OOT (Int)eractive Interface.
It allows interactive access
to the ROOT system via a C++ interpreter. */
#include <TRint.h>

#include <TCanvas.h>
#include <TF1.h>
#include <TVector.h>

int main(int argc, char *argv[])
{
   TRint app("app", &argc, argv);
   auto c{new TCanvas("c", "TrigFunct", 400, 100, 800 / 2 + 50, 600 / 2 + 50)};
   auto f1{new TF1("f1", "sin(x)/x", -5., 5)};
   f1->SetLineColor(kBlue+1);
   f1->SetTitle("sin(x)/x;x;sin(x)/x");
   f1->Draw();

   c->Modified();
   c->Update();

   app.Run();

   return 0;
}

/*
g++ app_04.cxx $(root-config --glibs --cflags --libs) -o app_04
*/
