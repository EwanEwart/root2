/*
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

*/

#include <TApplication.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRootCanvas.h>

int main(int argc, char* argv[])
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
   TApplication app
   (
      "app"
      ,&argc
      ,argv
   );
   auto c { new TCanvas("c","Trig Fcnts",0+400,0+100,800/2+50,600/2+50) };
   auto f1{ new TF1("f1","sin(x)",-5.,5.)};
   f1->SetLineColor(kBlue+1);
   f1->SetTitle("sin;x;sin(x)");
   f1->Draw();

   c->Modified();
   c->Update();
   auto rc = static_cast<TRootCanvas*>(c->GetCanvasImp());
   rc->Connect
   (
       "CloseWindow()"
      ,"TApplication"
      ,gApplication
      ,"Terminate()"
   );

   app.Run(); // start event loop

   return 0;
}
/*
g++ app_03.cxx $(root-config --glibs --cflags --libs) -o app_03
*/
