// TF1, TFormula, lambda

// entry point
void tf1_16(int choice = -1)
{
   switch (choice)
   {
   case 1: // TGraph 
   {
   	int npointx {20};
   	double xvec[npointx], yvec[npointx]; // allocate 2n doubles
   	for (int i{}; i<npointx; ++i) 
      { // populate 2n doubles
   		xvec[i] = i*0.1;
   		yvec[i] = 10*sin(xvec[i]+0.2);
   	}

   	auto g = new TGraph(npointx, xvec, yvec);

      cout<<"type g -> "<<typeid(g).name()<<endl;
	
      g->SetMarkerColor(kAzure); // TColor_01.C, colourWheel() to determine index of colour

      /*
      enum EMarkerStyle {kDot=1, kPlus, kStar, kCircle=4, kMultiply=5,
                      kFullDotSmall=6, kFullDotMedium=7, kFullDotLarge=8,
                      kFullCircle=20, kFullSquare=21, kFullTriangleUp=22,
                      kFullTriangleDown=23, kOpenCircle=24, kOpenSquare=25,
                      kOpenTriangleUp=26, kOpenDiamond=27, kOpenCross=28,
                      kFullStar=29, kOpenStar=30, kOpenTriangleDown=32,
                      kFullDiamond=33, kFullCross=34, kOpenDiamondCross=35,
                      kOpenSquareDiagonal=36, kOpenThreeTriangles=37,
                      kOctagonCross=38, kFullThreeTriangles=39,
                      kOpenFourTrianglesX=40, kFullFourTrianglesX=41,
                      kOpenDoubleDiamond=42, kFullDoubleDiamond=43,
                      kOpenFourTrianglesPlus=44, kFullFourTrianglesPlus=45,
                      kOpenCrossX=46, kFullCrossX=47, kFourSquaresX=48,
                      kFourSquaresPlus=49 };
      */
   	g->SetMarkerStyle(kOpenStar); // TAttMarker_01.png / TAttMarker_02.png

   	g->Draw(); // fine, draws
      
      break;
   }
   case 2: // TF1, lambda
   {
      auto f16 = new TF1("f16",[&](double* x,double* p){return p[0]*sin(x[0]); } , 0.0, 2*M_PI, 1);
      cout<<typeid(f16).name()<<endl;
      // auto f16 = new TF1("f16",[&](double* x,double *p){return p[0]*g->Eval(x[0]); }, 0,20 , 1);
      f16->SetParameter(0,2.0/M_PI);
      f16->Draw();
   }
   
   default:
   {
      cerr << "tf1_16( 1 | 2)" << endl;
      break;
   }
   };


}

/*
Using a Lambda function as a general C++ Functor object

From C++11 we can use both
- std::function or even better
- lambda functions
to create the TF1.

The lambda must have the right signature,
but can capture whatever we want.

For example we can make a TF1
from the TGraph::Eval function
as shown above.
Let's use a function parameter as the graph normalisation.
*/
