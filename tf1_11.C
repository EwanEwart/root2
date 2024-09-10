// TF1, TFormula, TMath
{
    auto f11 = new TF1("f11","TMath::Landau(x,[0],[1],0)",-5,10);
    f11->SetParameters(0.2,1.3);
    f11->Draw();
}

