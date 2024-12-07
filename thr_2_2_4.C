#include <iostream>
#include <thread>
#include <string>
using namespace std;

using widget_id = int;

using widget_data = string;

void update_data_for_widget(widget_id w, widget_data &data);

void display_status(widget_id const &wid, widget_data const &wd)
{
   cout << "display_status: { " << wid << "," << wd << " }" << endl;
}
void process_widget_data(widget_data wd)
{
   cout << "process_width_data ... " << endl;
}
void oops_again(widget_id w)
{
   widget_data data{"database engine no. 1"};
   // thread t(update_data_for_widget, w, data);
   thread t{update_data_for_widget, w, data};
   display_status(w,data);
   t.join();
   process_widget_data(data);
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
