/*

scenario word processor: one thread per editor window

*/

int const open_new_document 1;

struct user_command { int const type; };

void open_document_and_display_gui(string const& file) {}
bool done_editing() { return true; }
user_command get_user_input() { user_command uc{}; return uc; }
string get_filename_from_user(){ return "file name";}

void edit_document(string const& filename)
{
	open_document_and_display_gui(filename);
	while(!done_editing())
	{
		user_command cmd = get_user_input();
		if(cmd.type == open_new_document)
		{
			string const new_name = get_filename_from_user();
			thread t(edit_document, new_name);
			t.detach();
		}
		else
		{
			process_user_input(cmd);
		}
	}
}

void thread_2_4_word_processor()
{
	cout << "edit document" << endl;
}
