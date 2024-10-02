// TF1, TFormula
// F1 == formula 1 dimensional
// 2. Expression using variable x with parameters

void tf1_03 ()
{
   
	auto tf1_03
   {  new TF1
      (
           "f03"// name
         , "- ( [0] * pow( x, [1] ) )" // formula with parameters [0],[1]
         , -10.0 // xmin
         ,  10.0 // xmax
      )
   };

	tf1_03->SetParameter(0,.5);
	tf1_03->SetParameter(1,3);

	tf1_03->Draw();
}

