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
   auto nbinsx{10};
   auto xlow{0.};
   auto xup{5.};
   auto sum{0.0};
   auto mean{0.0};

   decltype(xlow) matrix[10][11]{};

   std::ifstream data_fs{};
   decltype(xlow) datum{};

   auto h{new TH1F("h", title, nbinsx, xlow, xup)};
   
   data_fs.open("expo.dat"); // no. of data items: 100
   auto idx{0};
   while (data_fs >> datum){
      h->Fill(datum);
      
      sum+=datum;

      matrix[idx/10][idx%10]=datum;
      std::cout<<idx/10<<'-'<<idx%10<<' '<<matrix[idx/10][idx%10]<<'\n';
      idx++;
   }
   data_fs.close();
   mean=sum/100.0;

   for (size_t r{}; r < 10; ++r)
   {
      for (size_t c{}; c<10; ++c)
         matrix[r][10]+= matrix[r][c];
   }
   
   for (size_t r{}; r < 10; ++r)
      std::cout << r << ". " << ( matrix[r,9] ) <<std::endl;

   std::cout<<"mean == "<<mean<<std::endl;
   
   h->Draw();
}
