#include <TROOT.h>
#include <TSystem.h> // gSystem-> ...
#include <TApplication.h>
#include <TCanvas.h>
#include <TMath.h>

#include <iostream>
/*
   Executing a ROOT macro from a ROOT macro using `ProcessLine`

   ProcessLine
   ===========
   process an interpreter line

   Process a single command line,
   either a C++ statement
   or an interpreter command starting with a ".".

Return the return value of the command cast to a long.
*/
void macro_02()
{
   // macro_exists 0 : path exists
   // macro_exists 1 : path doesn't exist
   auto macro_exists{!gSystem->AccessPathName("TF1_01.C")}; // if path exists
   std::cout << std::boolalpha << "TF1_01.C exists: " << macro_exists << std::endl;
   if (macro_exists)
   {
      // auto c { new TCanvas("c", "Trigonometric Functions", 0, 0, 800/2, 600/2) };
      // show graph / TROOT::ProcessLine
      Longptr_t error_code_ProcessLine = gROOT->ProcessLine(".x TF1_01.C");
      std::cerr << "TF1_01.C -> error_code_ProcessLine == " << error_code_ProcessLine << std::endl;
   }
   else // if path doesn't exist
   {
      // display text / TROOT::ProcessLine
      Longptr_t error_code_ProcessLine = gROOT->ProcessLine(".x extreme_C_01_12.C");
      std::cerr << "extreme_C_01_12.C -> error_code_ProcessLine == " << error_code_ProcessLine << std::endl;
   }
   
   {
      Longptr_t error_code_ProcessLine = gROOT->ProcessLine("4711 % 11");
      std::cerr << "4711 % 11 -> error_code_ProcessLine == " << error_code_ProcessLine << std::endl;
   }
   {
      Longptr_t error_code_ProcessLine = gROOT->ProcessLine("TMath::Sqrt(4711)");
      std::cerr << "TMath::Sqrt(4711) -> error_code_ProcessLine == " << error_code_ProcessLine << std::endl;
   }
}
/*

AccesPathName has a funny return code

Returns FALSE if one can access a file using the specified access mode.

The file name must not contain any special shell characters line ~ or $, 
in those cases first call ExpandPathName(). 
Attention, bizarre convention of return value!!

Reimplemented in 
TXNetSystem, 
TDCacheSystem, 
TGFALSystem, 
TNetSystem, 
TWebSystem, 
TUnixSystem, and 
TWinNTSystem.

Definition at line 1283 of file TSystem.cxx.

*/
