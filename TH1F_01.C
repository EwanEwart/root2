// Visualisation of a histogram filled with exponentially distributed, random numbers
#include <TF1.h>
#include <TH1F.h> // 1-Dim histogram with one ** float ** per ** channel **

void TH1F_01()
{
   auto xlow {0.0};
   auto xup {5.0};
   // auto nbinsx{10};
   auto nbinsx{100};
   // auto entries{100};
   auto entries{1000};
   decltype(xlow) params[]{1.,-1.};

   auto line{new TF1("line", "[0]+[1]*x", xlow, xup)};
   // line->SetParameters(1., 1.);
   // line->SetParameters(1., .5);
   // line->SetParameter(0,params[0]);
   // line->SetParameter(1,params[1]);
   // line->Draw();

   auto efunc{new TF1("efunc", "exp(line(x))", xlow, xup)};
   // efunc->SetParameters(1., 1.);
   // efunc->SetParameters(1., .5);
   efunc->SetParameter(0,params[0]);
   efunc->SetParameter(1,params[1]);

   // efunc->Draw("SAME");
   // efunc->Draw();

   auto h{new TH1F("h", "example histogram", nbinsx, xlow, xup)};
   for (auto i{0}; i < entries; ++i)
      h->Fill(efunc->GetRandom());
   h->Draw();
}
/*
Frequency distributions in ROOT are handled by a set of classes 
derived from the histogram class TH1, 
in our case TH1F. 
The letter F stands for “float”, 
meaning that the data type float is used 
to store the entries in one histogram bin.

We use yet another new feature of ROOT 
to fill this histogram with data, 
namely pseudo-random numbers 
generated with the method TF1::GetRandom, 
which in turn uses an instance of the ROOT class 

** TRandom ** 

created when ROOT is started. 

Data is entered in the histogram 
using the method TH1F::Fill in a loop construct. 

As a result, 
the histogram is filled with 1000 random numbers 
distributed according to the defined function. 

The histogram is displayed using the method TH1F::Draw(). 
You may think of this example as repeated measurements 
of the life time of a quantum mechanical state, 
which are entered into the histogram, 
therefore giving a visual impression 
of the probability density distribution.

Note that you will not obtain an identical plot 
when executing the lines above, 

depending on how the 
random number generator 
is initialised.

*/
