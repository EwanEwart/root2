/*
The class TH1F does not contain a convenient input format
from plain text files.

The following lines of C++ code do the job.
One number per line stored in the text file “expo.dat”
is read in via an input stream and
filled in the histogram until end of file is reached.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <TH1F.h>

#include <iostream>
#include <vector>

using BINS = std::vector<int>;

void put_into_bin(BINS &bins, double x, double from_x, double to_x)
{
   auto nbinsx{bins.size()};
   auto wbinsx{(to_x - from_x) / nbinsx}; // bin width
   // praedicat deciding which is the right frequency bin based on the given datum 
   auto is_in_bin{[](double min, double x, double max) { return (min <= x && x < max); }};
   for (size_t i{}; i < nbinsx; ++i)
      if (is_in_bin(i * wbinsx, x, (i + 1) * wbinsx))
      {
         bins[i] += 1;
         break;
      }
}

void TH1_02()
{
   auto title{"histogramme from file data"};
   auto nbinsx{10};
   auto xlow{0.};
   auto xup{5.};
   BINS bins(nbinsx);

   std::ifstream data_fs{};
   decltype(xlow) datum{};

   auto h{new TH1F("h", title, nbinsx, xlow, xup)};

   data_fs.open("expo.dat"); // no. of data items: 100
   while (data_fs >> datum)
   {
      h->Fill(datum);
      put_into_bin(bins, datum, xlow, xup);
   }

   data_fs.close();

   // total number of entries in bins
   size_t entries_of_values_in_bins{};
   for(auto i:bins)
   {
      entries_of_values_in_bins+=i;
   }
   std::cout
      <<"Number of entries in bins == "
      <<entries_of_values_in_bins
      <<std::endl;
   
   // console histogramme
   auto print_console_histogramme {[](BINS const& bins,char character='-'){
      unsigned short no{};
      for(size_t bin_no:bins)
      {
         std::cout<<std::setw(4)<<++no<<": "<<std::setw(4)<<bin_no<<'|';
         for (auto n{0};n<bin_no;++n)
            std::cout << character;
         std::cout<<std::endl;
      }
   }};
   print_console_histogramme(bins);

   // CERN histogramme
   h->Draw();
}
