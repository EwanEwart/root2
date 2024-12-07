#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <string>
using std::string;

void open_document_and_display_gui(string const& filename)
{
   cout<<"-> open_document_and_display_gui"<<endl;
}

bool done_editing()
{
   cout<<"-> done_editing"<<endl;
   return false;
}

enum command_type
{
     open_new_document
   , close_document
   , save_document
   , save_document_as
};

struct user_command
{
   command_type type;

   user_command()
   : type(open_new_document)
   {
   }
};

user_command get_user_input()
{
   cout<<"-> get_user_input"<<endl;

   return user_command();
}

string get_filename_from_user()
{
   cout<<"-> get_filename_from_user"<<endl;

   return "foo.doc";
}

void process_user_input(user_command const &cmd)
{
   cout<<"-> process_user_input"<<endl;
}

void edit_document(string const& filename)
{
   cout<<"-> edit_document"<<endl;
   auto static limit{1};

   open_document_and_display_gui(filename);
   while (!done_editing())
   {
      if(++limit>3) break;

      user_command cmd = get_user_input();
      if (cmd.type == open_new_document)
      {
         string const new_name = get_filename_from_user();
         cout<<"new thread: edit_document, detach"<<endl;
         /////////////////////////////////////
         thread t(edit_document, new_name);
         /////////////////////////////////////
         t.detach();
      }
      else
      {
         process_user_input(cmd);
      }
   }
}

int main()
{
   edit_document("bar.doc");

   return 0;
}
