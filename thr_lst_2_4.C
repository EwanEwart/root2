#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <thread>
using std::thread;

#include <string>
using std::string;


enum command_type
{
   open_new_document,
   close_document,
   save_document,
   save_document_as
};

struct user_command
{
   command_type type;

   user_command()
       : type(open_new_document)
   {
   }
};


string get_filename_from_user();
void edit_document(string const &filename);
void open_document_and_display_gui(string const &filename);
user_command get_cmd_input();
bool done_editing(string const& filename);
void process_cmd_input(user_command const &cmd);


void open_document_and_display_gui(string const &filename)
{
   cout << "-> open_document_and_display_gui for document "<< filename << endl;
}

bool done_editing(string const& filename)
{
   cout << "-> done_editing "<< filename << endl;
   return false;
}

user_command get_cmd_input()
{
   cout << "-> get_cmd_input" << endl;

   return user_command();
}

string get_filename_from_user()
{
   cout << "-> get_filename_from_user" << endl;

   string doc;
   cout<<"Enter document to edit ... "; cin>>doc;
   edit_document(doc);

   return doc;
}

void process_cmd_input(user_command const &cmd)
{
   cout << "-> process_cmd_input" << endl;
}

void edit_document(string const &filename)
{
   cout << "-> edit_document "<< filename << endl;
   auto static limit{0};

   open_document_and_display_gui(filename);
   while (!done_editing(filename))
   {
      if (++limit > 3)
         break;

      user_command cmd = get_cmd_input();
      if (cmd.type == open_new_document)
      {
         string const new_name = get_filename_from_user();
         cout << "new thread: edit_document ("<<new_name<<"), detach" << endl;
         /////////////////////////////////////
         thread t(edit_document, new_name);
         /////////////////////////////////////
         t.detach();
      }
      else
      {
         process_cmd_input(cmd);
      }
   }
}

void thr_2_4()
{
   edit_document(get_filename_from_user());
}

int main()
{
   thr_2_4();

   return 0;
}
