// TF1, TFormula

void tf1_14(int choice=-1)
{
	// TF1 obj "fcos"
	auto fcos { new TF1 ("fcos", "[0] * cos(x)", 0., 10.) };
	fcos->SetParNames( "cos");
	fcos->SetParameter( 0, 1.1);

	// TF1 obj "fsin" 
	auto fsin { new TF1 ("fsin", "[0] * sin(x)", 0., 10.) };
	fsin->SetParNames( "sin");
	fsin->SetParameter( 0, 2.1);

	// TF1 obj fCos_plus_fSin references TF1 objects "fcos" & "fsin" 
	auto fCos_plus_Sin { new TF1 ("fsc", "fcos + fsin") };

	// TF1 object fSin_plus_Sin references TF1 object "fsc" 
	auto fSin_plus_Sin { new TF1 ("fs2", "fsc + fsc") };

// That is, TF1 functions may be created as the predefined ones, e.g., cosine(x)
	auto cosine { new TF1 ("cosine", "cos(x)",0.,10.) };
	auto sine { new TF1 ( "sine", "sin(x)",0.,10.) };
   auto cosine_plus_sine {new TF1("cps","cosine(x)+sine(x)",.0,10.) };
	switch (choice) {
		case 1: fcos->Draw(); break;
		case 2: fsin->Draw(); break;
		case 3: fCos_plus_Sin->Draw(); break;
		case 4: fSin_plus_Sin->Draw(); break;
		case 5: cosine->Draw();break;
		case 6: sine->Draw();break;
      case 7: cosine_plus_sine->Draw();break;
		default:
		cerr<<"unkown option"<<endl;
	}
}

/*
TF1 objects can reference other TF1 objects
of type A (?) or B (?)defined above.
This excludes CLing or compiled functions.
However, there is a restriction.
A function cannot reference a basic function
if the basic function is a polynomial polN.
*/ 
