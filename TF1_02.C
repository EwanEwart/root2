// TFormula : [0] * sin(x) + [1] * exp(-[2] * x )
// 2. Expression using variable x with parameters

void tf1_02()
{
 	auto f02
   {
      new TF1
      (
          "f02" // name
         ,"[0] * sin(x) + [1] * exp( -[2] * x)" // three parameters: [0],[1],[2]
         ,0.0  // xmin
         ,10.0 // xmax
      )
   }
   ;

	f02->SetParameter(0,10);
	f02->SetParameter(1,15);
	f02->SetParameter(2,1.5);

	f02->Draw();

}
void TF1_02()
{
   tf1_02();
}

	
