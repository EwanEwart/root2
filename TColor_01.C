/*
TColor

https://root.cern.ch/doc/master/classTColor.html

- RGB red, green, blue
- HLS hue, light and saturation
Two sets of colours are initialised;

    The basic colours: colours with index from 0 to 50.
    The colour wheel: colours with indices from 300 to 1000.


Basic colours
=============

The following image displays the 50 basic colours.
*/
auto colourTable()
{
   auto c = new TCanvas("c","Fill Area colours",0,0,500,200);
   c->DrawColorTable();
   return c;
}


/*
The colour wheel
================

The wheel contains the recommended 216 colours to be used in web applications.
*/
auto colourWheel()
{
   auto w  = new TColorWheel();
   auto cw = new TCanvas("cw","cw",0,0,400,400);
   w->SetCanvas(cw);
   w->Draw();
}

void TColor_01()
{
   colourTable();
}
