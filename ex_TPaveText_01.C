TCanvas* ex_TPaveText_01() {
	TCanvas* cnv = new TCanvas("cnv");
	TPaveText* pt = new TPaveText(/*x1*/.05,/*y1*/.1,/*x2*/.95,/*y2*/.8); // "br" == border right
	// TPaveText* pt = new TPaveText(.05, .1, .95, .8,"nb");// no border

	// TText *TPaveText::AddText(char const *label);
	// TLine *TPaveText::AddLine(Double_t x1, Double_t y1, Double_t x2, Double_t y2);
	auto txt_01 = pt->AddText("A TPaveText object can contain several lines of text.");
	txt_01->SetTextColor(kGreen-1);
	auto txt_02 = pt->AddText("They are added to the TPave using the TPaveText::AddText method.");
	txt_02->SetTextColor(kPink-1);
	auto txt_03 = pt->AddText("The TPaveText::AddLine method adds a line:");
	pt->AddLine(.0,.4, 1.,.4);
	pt->AddText("Even complex TLatex formulas can be added:");
	TText *t1 = pt->AddText("F(t) = #sum_{i=-#infty}^{#infty}A(i)cos#[]{#frac{i}{t+i}}");
	t1->SetTextColor(kBlue);

	pt->Draw();

	TText *t2 = pt->GetLineWith("Even");
	t2->SetTextColor(kOrange + 1);
	// pt->SetBorderSize(0);

	return cnv;
}

