/*
https://root.cern/manual/creating_a_user_application/

Batch example generating a PDF file
===================================

A C++ standalone application must contain the main() function, 
the starting point for the application execution.

The first lines of the C++ file include ROOT header files. 
The names of the ROOT header files are almost always the same 
as the class names (here TF1 and TCanvas).

Linux :
------
g++ app_02.C $(root-config --glibs --cflags --libs) -o app_02

Windows :
--------
cl -nologo -MD -GR -EHsc demo1.cxx -I %ROOTSYS%\include /link -LIBPATH:%ROOTSYS%\lib libCore.lib libGpad.lib libHist.lib



Note
----
You can use root-config --cflags 
to be sure to use the correct compiler flags (Debug vs Release)

The following message is displayed:

Info in <TCanvas::Print>: pdf file app_02.pdf has been created

The app_02.pdf file is saved in the current working directory. 
The pdf file contains the plot of the f1 function
*/

#include <TCanvas.h>
#include <TF1.h>

int main(int argc, char **argv)
{
    auto *c = new TCanvas("c", "EE: standalone ROOT application", 0, 0, 800, 600);

    auto *f1 = new TF1("f1", "sin(x)/x", -10, 10);
    f1->SetLineColor(kBlue + 1);
    f1->SetTitle("sin(x)/x;x-axis;y-axis"); // title / lable x-axis / lable y-axis
    f1->Draw();

    c->Print("app_02.C_generated.pdf");
    c->SaveAs("app_02.C_generated.svg","svg");
    c->SaveAs("app_02.C_generated.png","png");
    c->SaveAs("app_02.C_generated.gif","gif");
    c->SaveAs("app_02.C_generated.jpg","jpg");

    return 0;
}

/*
$ apt show libpcre3-dev
Package: libpcre3-dev
Version: 2:8.39-15.1
Priority: optional
Section: universe/libdevel
Source: pcre3
Origin: Ubuntu
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Original-Maintainer: Matthew Vernon <matthew@debian.org>
Bugs: https://bugs.launchpad.net/ubuntu/+filebug
Installed-Size: 2,309 kB
Depends: libc-dev, libpcre3 (= 2:8.39-15.1), libpcre16-3 (= 2:8.39-15.1), libpcre32-3 (= 2:8.39-15.1), libpcrecpp0v5 (= 2:8.39-15.1)
Download-Size: 601 kB
APT-Manual-Installed: yes
APT-Sources: http://de.archive.ubuntu.com/ubuntu oracular/universe amd64 Packages
Description: Old Perl 5 Compatible Regular Expression Library - development files
 This is a library of functions to support regular expressions whose syntax
 and semantics are as close as possible to those of the Perl 5 language.
 .
 New packages should use the newer pcre2 packages, and existing
 packages should migrate to pcre2.
 .
 This package contains the development files, including headers, static
 libraries, and documentation.

*/
