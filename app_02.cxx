#include "TCanvas.h"
#include "TF1.h"

/*
https://root.cern/manual/creating_a_user_application/
*/

int main(int argc, char const *argv[])
{

   auto c { new TCanvas("c", "Trigonometric Functions", 0, 0, 800, 600) };

   auto f1 { new TF1("f1","sin(x)", -5, 5) };

   f1->SetTitle("f(x)=sin(x);x; sin(x)");
   f1->SetLineColor(kRed+1);
   f1->SetLineStyle(1);
   f1->SetLineWidth(1);

   f1->Draw();

   c->Print("app_02.pdf");

   // sudo apt install libpcre3-dev on Ubuntu 24.10

   // g++ app_02.cxx $(root-config --glibs --cflags --libs) -o app_02
   // $ ./app_02 
   // display app_02.pdf

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
