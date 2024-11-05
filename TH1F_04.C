/*
https://www.lotto-bayern.de/static/gamebroker_2/de/download_files/archiv_lotto.zip

to be finished
*/
#include <iostream>
#include <iomanip>
#include <fstream>
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

void TH1F_04()
{
   auto nbinsx{49};
   auto xlow{1};
   auto xup{50};
   BINS bins(nbinsx);

   int datum{};

   #define FILE_IN_1 "lotto.since.1955.csv"
   #define FILE_IN_2 "lotto.since.1955.2.lines.csv"
   #define FILE_OUT "lotto.since.1955.no.only.csv"
   // auto fp_data_in = std::fopen(FILE_IN,"r");
   auto fp_data_in = std::fopen(FILE_IN_2,"r");
   auto fp_data_out = std::fopen(FILE_OUT,"w");
   
   if (fp_data_in)
   {
      std::cout<<FILE_IN_2<<" successfully."<<std::endl;
   }
   else
   {
      std::cerr<<"Failure : Could not open ."<<FILE_IN_2<<std::endl;
      return;
   }
   
   if (fp_data_out)
   {
      std::cout<<"Opened "<<FILE_OUT <<" successfully."<<std::endl;
   }
   else
   {
      std::cerr<<"Failure : Could not open file "<<FILE_OUT<<std::endl;
      return;
   }
   
   unsigned short field_no{};
   for ( size_t filed_no{}; EOF != fscanf(fp_data_in,"%d",&datum); ++field_no)
   {
      auto const total_columns{11};
      auto column{ (field_no%total_columns) };
      if ( 2 < column && column < 9 )
      {
         put_into_bin(bins, datum, xlow, xup);
         std::fprintf(fp_data_out,"%d\t",datum);
         std::cout<<field_no%11<<'-';
      }
   }
   std::cout<<std::endl;
   
   std::fclose(fp_data_in);
   std::fclose(fp_data_out);

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
   auto print_console_histogramme {[](BINS const& bins,char character='-',double scale=.1){
      unsigned short no{};
      for(size_t bin_no:bins)
      {
         std::cout<<std::setw(4)<<++no<<": "<<std::setw(4)<<bin_no<<'|';
         for (auto n{0};n<bin_no*scale;++n)
            std::cout << character;
         std::cout<<std::endl;
      }
   }};
   print_console_histogramme(bins);

}
