#include <iostream>
using std::cout;
using std::endl;
using std::ostream;


// typedef float(*fp)(float, float, float); // new type: fp
using fp = float(*)(float, float, float);// new type: fp

struct ColourRGB
{
   unsigned short r = 128;
   unsigned short g = 128;
   unsigned short b = 128;
};
struct Point
{
   float x;
   float y;
   float z;

   ///////////////////////////////////////////////////////
   // more attributes of a point in a point-cloud
   ColourRGB c = {222, 222, 222};
   // a type fp: a function pointer
   fp tangent{[](float x, float m = 0.5, float c = 0) { return m * x + c; }};
   fp normal{[](float x, float m = -1.0/0.5, float d = 0) { return -m * x + d; }};
   
   // member function
   float square(float x){return x*x;};
};
ostream &operator<<(ostream &os, ColourRGB const &c)
{
   os << '(' << c.r << ',' << c.g << ',' << c.b << ')';
   return os;
};
ostream &operator<<(ostream &os, Point const &p)
{
   os << '(' << p.x << ',' << p.y << ',' << p.z << ',' << p.c << ')';
   return os;
};

void pointCloud()
{
   ColourRGB c1{202, 101, 32};
   Point p1{1, 2, 3, c1};

   cout << "c1 == " << c1 << endl;
   cout << "p1.c == " << p1.c << endl;
   cout << "p1 == " << p1 << endl;

   ColourRGB c2;
   cout << "c2 == " << c2 << endl;

   Point p2{3, 2, 1};
   cout << "p2.c == " << p2.c << endl;
   cout << "p2 == " << p2 << endl;

   Point p3{7, 7, 7};
   cout<<"p3 == "<<p3<<endl;
   cout<<"p3.tangent(x) == ";
   for (float x{-5.0}; x <= 5.0; ++x) cout << p3.tangent(x, .5, 1.0) << "   "; cout << endl;
   cout<<"p3.normal(x) == ";
   for (float x{-5.0}; x <= 5.0; ++x) cout << p3.normal(x, .5, 1.0) << "   "; cout << endl;
   cout<<"p3.square(x) == ";
   for (float x{-5.0}; x <= 5.0; ++x) cout << p3.square(x) << "   "; cout << endl;

   Point p4
   {  -7, -7, -7
      ,c1
      ,[](float x,float m,float c){return  m*x+3.1415f*c;} // custom function pointers via lambda
      ,[](float x,float m,float d){return -m*x+3.1415f*d;} // custom function pointers via lambda
   };
   cout<<"p4 == "<<p4<<endl;
   cout<<"p4.normal == ";
   cout<<"p4.tangent(x) == ";
   for (float x{-5.0}; x <= 5.0; ++x) cout << p4.tangent(x, .5, 1.0) << "   "; cout << endl;
   cout<<"p4.normal(x) == ";
   for (float x{-5.0}; x <= 5.0; ++x) cout << p4.normal(x, .5, 1.0) << "   "; cout << endl;
}
