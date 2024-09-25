// TF1, TFormula
// F1 == formula 1 dimensional
// 2. Expression using variable x with parameters

void tf1_04()
{
	auto f04
   {
      new TF1
      (
           "f04" // name
         , "gaus(0) * expo(3) + ypol3(5) * x" // 5 params !
         ,  0 // xmin
         , 25 // xmax
      )
   };
	f04->SetParameters(4,2,7,3,.1); // gaus(0) <- 3 params; expo(3) <- 2 params == 5 params
	f04->Draw();
}

/*

gaus(0)   is a substitute for [0] * exp( -0.5 * ( ( x - [1] ) / [2] ) ** 2)
and (0)   means start numbering parameters at 0

gausn(0)  is a substitute for [0] * exp( -0.5 * ( ( x - [1] ) / [2] ) ** 2) / ( sqrt(2*pi) * [2]))
and  (0)  means start numbering parameters at 0

expo(3)   is a substitute for exp( [3] + [4] * x)

pol3(5)   is a substitute for par[5] * x**0 + par[6] * x**1 + par[7] * x**2 + par[8] * x**3
   PolN stands for Polynomial of degree N

gaus(x, [0..2]) is a more explicit way of writing gaus(0)

expo(y, [3..4]) is a substitute for exp( [3] + [4] * y)

*/

