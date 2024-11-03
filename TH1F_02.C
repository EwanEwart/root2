/*
The class TH1F does not contain a convenient input format
from plain text files.

The following lines of C++ code do the job.
One number per line stored in the text file “expo.dat”
is read in via an input stream and
filled in the histogram until end of file is reached.
*/
#include <iostream>
#include <fstream>
#include <TH1F.h>

void TH1F_02()
{
   auto title{"histogramme from file data"};
   auto nbinsx{100};
   auto xlow{0.};
   auto xup{5.};
   auto sum{0.0};
   auto mean{0.0};

   std::ifstream data_fs{};
   decltype(xlow) datum{};

   auto h{new TH1F("h", title, nbinsx, xlow, xup)};
   
   data_fs.open("expo.dat"); // no. of data items: 100
   while (data_fs >> datum){
      h->Fill(datum);
      sum+=datum;
   }
   data_fs.close();
   mean=sum/100.0;

   std::cout<<"mean == "<<mean<<std::endl;
   
   h->Draw();
}
