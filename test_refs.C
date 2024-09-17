#include<iostream>
#include<string>
using namespace std;
class C1
{
    string& s1;
    int i1;
    string s2{"?"};
public:
    C1():s1{s2},i1{-1}{}
    // C1():s1{string{"?"}},i1{-1}{}
    C1(string & s1,int i1):s1{s1},i1{i1}{}
    void operator=(C1 c){s1=c.s1;i1=c.i1;}
    string get_s1(){return s1;}
    int get_i1(){return i1;}
    void set_s1(string s){s1=s;}
    void set_i1(int i){i1=i;}
    bool operator==(C1 c1){return c1.s1 == s1 && c1.i1 == i1;}
};

void test_refs()
{
    string strrsc{"String resource"};

    C1 s1{strrsc, 44};
    // C1 s1{"s1", 44};
    cout << "s1 : " << s1.get_s1() << " / " << s1.get_i1() << endl;

    C1 s2{s1};
    cout << "s2 : " << s2.get_s1() << " / " << s2.get_i1() << endl;

    C1 s3 = s1;
    cout << "s3 : " << s3.get_s1() << " / " << s3.get_i1() << endl;

    C1 s4;
    cout << "s4 : " << s4.get_s1() << " / " << s4.get_i1() << endl;

    C1 s5;
    s5.set_s1("s5");
    s5.set_i1(55);
    cout << "s5 : " << s5.get_s1() << " / " << s5.get_i1() << endl;

    s5=s3; // error: object of type 'C1' cannot be assigned because its copy assignment operator is implicitly deleted
    // now implemented above

    string strrsc6 {"strrsc6"};
    C1 s6{strrsc6, 66};
    // C1 s1{"s1", 44};
    cout << "s1 : " << s1.get_s1() << " / " << s1.get_i1() << endl;

    C1& r5 {s5};
    C1& r6 {s6};
    cout << "r5 : " << r5.get_s1() << " / " << r5.get_i1() << endl;
    cout << "r6 : " << r6.get_s1() << " / " << r6.get_i1() << endl;

    r5=r6;
    cout << "r5 : " << r5.get_s1() << " / " << r5.get_i1() << endl;
    cout << "r6 : " << r6.get_s1() << " / " << r6.get_i1() << endl;
    cout << "s5 : " << s5.get_s1() << " / " << s5.get_i1() << endl;
    cout << "s6 : " << s6.get_s1() << " / " << s6.get_i1() << endl;
    
    if(s1==s2) cout<<"s1==s2"<<endl; else cout<<"s1!=s2"<<endl;
    if(s2==s3) cout<<"s2==s3"<<endl; else cout<<"s2!=s3"<<endl;
    if(s3==s5) cout<<"s3==s5"<<endl; else cout<<"s3!=s5"<<endl;
    if(r6==r5) cout<<"r6==r5"<<endl; else cout<<"r6!=r5"<<endl;
}
