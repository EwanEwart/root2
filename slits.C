// Drawing the interference pattern of light
// falling on a grid with
//
// n slits and
//
// ratio r of
// slit width
// over distance between slits.
//
// Source:
// /home/ewan/ROOT/slits.C

auto pi = TMath::Pi();

// function code in C
double single(double *x, double *par)
{
   return pow(sin(pi * par[0] * x[0]) / (pi * par[0] * x[0]), 2);
}

double nslit0(double *x, double *par)
{
   return pow(sin(pi * par[1] * x[0]) / sin(pi * x[0]), 2);
}

double nslit(double *x, double *par)
{
   return single(x, par) * nslit0(x, par);
}

TF1* getTF1(double(*pFunc)(double*,double*),double r,double ns, Color_t colour)
{
   auto pTF1
   {
      new TF1
      (
           "pTF1" // name internal memory management
         , pFunc  // double (*)(double*,double*) <- nslit(double *x, double *par)
         , -5.001 // xmin
         , 5.     // xmax
         , 2      // npar
      )
   }
   ;
   pTF1->SetNpx(500);

   // set parameters, as read in above
   pTF1->SetParameter(0, r);
   pTF1->SetParameter(1, ns);
   pTF1->SetLineColor(colour);

   return pTF1;
}

// This is the entry point of the program
void slits()
{
   // Input
   //
   float r;    // width/distance ratio
   float ns;   // no. of slits

   // request user input
   cout << "slit width / g ? ";
   cin >> r; // scanf("%f", &r);
   // r = 0.2;

   // request user input
   cout << "no. of slits? ";
   cin >> ns; //   scanf("%f",&ns);
   // ns = 2;

   cout
       << "interference pattern for "
       << ns << " slits, "
       << "width/distance ratio: " << r
       << endl;
   
   // canvas
   auto c1 {new TCanvas("c1","slits",600,400)};

   // TF1s ptrs
   auto Fnslit       { getTF1( nslit  , r , ns , kRed   +1 ) };
   auto Fnslit0      { getTF1( nslit0 , r , ns , kBlue  +1 ) };
   auto FnslitSingle { getTF1( single , r , ns , kGreen +1 ) };

   // draw the interference pattern for a grid with n slits
   Fnslit         -> Draw();
   Fnslit0        -> Draw("SAME"); // same canvas
   FnslitSingle   -> Draw("SAME"); // same canvas

}
