// TF1, TFormula
// F1 == formula one-dimensional
// 1. Expression using variable x and no parameters
void tf1_01()
{
   auto fa1
   {
      new TF1
      (
           "fa1"        // char const *   name
         , "sin(x)/x"   // char const *   formula; here no parameters
         ,  0.0         // Double_t       xmin = 0
         , 10.0         // Double_t       xmax = 1
                        // EAddToList     addToGlobList = EAddToList::kDefault
                        // bool           vectorize = false
      )
   };
   fa1->SetTitle("title : sin(x)/x;x-axis;y-axis"); // TGraph, default "Graph"
   fa1->SetName("TF1_no_01"); // TGraph, default "Graph"
   fa1->Draw();
}

/*
F1 constructor using a formula definition.

See TFormula constructor for explanation of the formula syntax.

See tutorials: fillrandom, first, fit1, formula1, multifit for real examples.

Creates a function of type A or B between xmin and xmax

if formula has the form "fffffff;xxxx;yyyy",
it is assumed that the formula string is
"fffffff" and "xxxx" and "yyyy" are
the titles for the X and Y axis respectively.

*/
