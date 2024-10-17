/*
Interactive example displaying a canvasPermalink
================================================

Use TApplication 
to display the output on a screen. 

TApplication creates a ROOT application environment 
that provides an interface 
- to the windowing system event loops and 
- event handlers.

To run the canvas as a standalone application 
you must create a TApplication object. 

Calling the Run() method starts the event loop.

*/

#include<TCanvas>
#include<TF1.h>
#include<TRootCanvas>
#include <TApplication>

int main(int argc, char const *argv[])
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
   TApplication
   (
      "app"
      ,&argc,argv);


   return 0;
}
