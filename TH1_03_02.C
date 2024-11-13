/*
https://www.lotto-bayern.de/static/gamebroker_2/de/download_files/archiv_lotto.zip

losa.txt & lotto.txt: csv <- tabs, convert blanks to 0, double tabs to one tab
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> // sort

#include <TH1I.h> // ROOT

// This ctype facet classifies tabs and endlines as whitespace
// struct csv_whitespace : std::ctype<char>
// {
//     static const mask* make_table()
//     {
//         // make a copy of the "C" locale table
//         static std::vector<mask> v(classic_table(), classic_table() + table_size);
//         v['\t'] |=  space; // tab will be classified as whitespace
//         v['\n'] |=  space; // nl will be classified as whitespace
//         v[' '] &= ~space; // space will not be classified as whitespace
//         //v['\n'] &= ~space; // nl will not be classified as whitespace
//         return &v[0];
//     }
//     csv_whitespace(std::size_t refs = 0) : ctype(make_table(), false, refs) {}
// };

struct BIN
{
   unsigned short no;
   unsigned short datum;
};

using BINS = std::vector<BIN>;

void put_into_bin(BINS &bins, double x, double from_x, double to_x)
{
   auto nbinsx{bins.size()};
   auto wbinsx{(to_x - from_x) / nbinsx}; // bin width
   // praedicat deciding which is the right frequency bin based on the given datum 
   auto is_in_bin{[](double min, double x, double max) { return (min <= x && x < max); }};
   for (size_t i{}; i < nbinsx; ++i)
   {
      bins[i].no=i+1; // [1,49], not [0,48]
      if (is_in_bin(i * wbinsx, x, (i + 1) * wbinsx))
      {
         bins[i].datum += 1;
         break;
      }
   }
}

void TH1_03_02()
{
   auto nbinsx{49};
   auto xlow{0};
   auto xup{50};
   BINS bins(nbinsx);

   std::ifstream ifs_data{};
   // std::ofstream ofs_data{};
   unsigned short datum{};

   auto title{"uniform distribution[1,49]"};
   
   ifs_data.open("lotto.dat");
   // ofs_data.open("losa_lotto.nos.only.csv");
   
   if 
   (
      ifs_data.is_open()
      // &&
      // ofs_data.is_open()
   )
   {
      std::cout<<"Opened i/o files successfully."<<std::endl;
   }
   else
   {
      std::cerr<<"Failure : Could not open i/o files."<<std::endl;
      return;
   }
   
   // ifs_data.imbue(std::locale(ifs_data.getloc(), new csv_whitespace));

   auto h{new TH1I("h", title, nbinsx, xlow, xup)}; // ROOT

   unsigned short field_no{};
   for ( size_t filed_no{}; ifs_data >> datum; ++field_no)
   {
      auto const total_columns{11};
      auto column{ (field_no%total_columns) };
      // if ( 2 < column && column < 9 )
      // {
         h->Fill(datum); // ROOT
         put_into_bin(bins, datum, xlow, xup);
         // ofs_data<<datum<<'\t';
         // std::cout<<field_no%11<<'-';
      // }
   }
   std::cout<<std::endl;
   
   ifs_data.close();

   // total number of entries in bins
   size_t sum_bin_values{};
   for(auto bin:bins)
      sum_bin_values+=bin.datum;
   std::cout
      <<"Number of entries in bins == "
      <<sum_bin_values
      <<std::endl;
   
   // console histogramme
   auto print_console_histogramme {[](BINS const& bins,char character='-',double scale=1)
   {
      unsigned short no{};
      for(auto bin:bins)
      {
         std::cout<<std::setw(4)<<bin.no<<": "<<std::setw(4)<<bin.datum<<'|';
         for (auto n{0};n<bin.datum*scale;++n)
            std::cout << character;
         std::cout<<std::endl;
      }
      std::cout<<'\n'<<std::endl;
   }};
   print_console_histogramme(bins);

   // in place sort
   std::sort(bins.begin(),bins.end(),[](BIN const& b1, BIN const& b2){return b1.datum < b2.datum;});
   auto diff {bins[48].datum-bins[0].datum+1};
   std::cout<<"frequencies ["<<bins[0].datum<<","<<bins[48].datum<<"]"<<std::endl;
   std::cout<<"diff == "<<diff<<std::endl;
   print_console_histogramme(bins);

   // CERN histogramme
   h->Draw(); // ROOT


}
