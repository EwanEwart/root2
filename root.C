#include<TRint.h>
#include<TROOT.h>

int main(int argc, char **argv)
{
    TRint *theApp = new TRint("ROOT example", &argc, argv);

    // Init Intrinsics, build all windows, and enter event loop
    theApp->Run();

    return (0);
}

void root() {
    main(0,nullptr);
}