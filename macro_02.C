void macro_02()
{
   // rtn 0 : path exists
   // rtn 1 : path doesn't exist
   auto rtn {gSystem->AccessPathName("extreme_C_01_12.root")};
   cout << "rtn == " << rtn << endl;
   if (rtn)
   {
      int errorCode = gROOT->ProcessLine(".x extreme_C_01_12.C"); // display text / TROOT::ProcessLine
      cerr << "errorCode == " << errorCode << endl;
   }
   else
   {
      int errorCode = gROOT->ProcessLine(".x TF1_01.C"); // show graph / TROOT::ProcessLine
      cerr << "errorCode == " << errorCode << endl;
   }
}
