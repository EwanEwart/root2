#include <iostream>
#include <thread>
#include <string>
#include <functional>
using namespace std;

using widget_id = int;
using widget_data = string;

// // ------------------------------------problem ref & ------v
void update_data_for_widget(widget_id const w, widget_data & data)
{
   string tmp{"{ "};
   tmp+=to_string(w);
   tmp+=",";
   tmp+="commenucation server no. 3";
   tmp+=" }";
   data=tmp;
}

// ref -----------------------------------------------------v
void display_status(widget_id const &wid, widget_data const & wd)
{
   cout << "display_status => { " << wid << "," << wd << " }" << endl;
}
void process_widget_data(widget_data wd)
{
   cout << "process_widget_data => "<<wd<< endl;
}
void oops_again(widget_id wid)
{
   widget_data wd{"database engine no. 1"};
   ///////////////////////////////////////////////
   thread t{update_data_for_widget, wid, ref(wd)}; // std::ref
   ///////////////////////////////////////////////
   display_status(wid,wd);
   t.join();
   process_widget_data(wd);
}
void thr_2_2_4()
{
   oops_again(1);
}
int main(int argc, char const *argv[])
{
   thr_2_2_4();

   return 0;
}
