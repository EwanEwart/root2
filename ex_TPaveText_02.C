// virtual TList *GetListOfLines() const {return fLines;}
// public: TObject *Last() const override;
void ex_TPaveText_02()
{
	TPaveText *pt = new TPaveText(/*x1*/.05,/*y1*/.3,/*x2*/.95,/*y2*/.6);// br == bottom right shadow

	pt->AddText("This line is blue");
	((TText*)pt->GetListOfLines()->Last())->SetTextColor(kBlue+1);

	pt->AddText("This line is red");
	((TText*)pt->GetListOfLines()->Last())->SetTextColor(kRed+1);

	TText* textPink = pt->AddText("This line is pink");
	textPink->SetTextColor(kPink+1);

	pt->Draw();
}
