/*
reference only command pattern version
ref concept:
root [0] string ln {"Ewart"}
(std::string &) "Ewart"
root [1] string fn {"Rachel"}
(std::string &) "Rachel"
root [2] vector<reference_wrapper<string>> v1 {}
(std::vector<std::reference_wrapper<std::string> > &) {}
root [3] v1.push_back(fn)
root [4] v1.push_back(ln)
root [5] for(auto const& i:v1)cout<<i.get()<<'\n';cout<<endl;
Rachel
Ewart
*/

#include <iostream>

using namespace std;

/*
Source : https://www.geeksforgeeks.org/command-pattern-c-design-patterns/
The Command Pattern is a behavioural design pattern,
which focuses on encapsulating a request as an object,
thereby decoupling the sender of the request from the receiver.
This pattern allows you to
- parameterise objects with commands,
- delay or queue a request’s execution, and
- support undoable operations.
It’s a fundamental pattern for implementing a wide range of functionality in software systems.
*/

/*
1. Command Interface or Abstract Class
--------------------------------------
This is an abstract class,
which serves as *interface*,
that declares an *Execute* method,
defining the contract for concrete commands.
It ensures that all commands have a standardised method
to perform their actions.
*/
class Command
{
public:
   // Command& operator=(Command &) = default; // to prevent slicing
   // Command(const Command&) = default; // to prevent slicing
   virtual ~Command() {}
   virtual void Execute() const = 0;
};

/*
2. Receiver
-----------
The receiver is responsible for performing the actual work
when a command is executed.
It knows how to carry out the requested action.
For example, in a home automation system,
the receiver could be a “Light” object
that understands how to turn a light on and off.
*/
class Receiver
{
   string payload_;

public:
   Receiver(string const &pay_load) : payload_{pay_load} {}
   void perform_action()
   {
      cout << "Receiver: " << payload_ << " ..." << endl;
   }
};

/*
3. Concrete Command
-------------------
Concrete command classes
implement the Command interface or
inherit from the abstract class.
Each concrete command encapsulates
a specific action to be performed.
For instance,
you might have concrete commands
to turn on lights, open files, or send messages.
*/
class ConcreteCommand : public Command
{
   Receiver &receiver_;

public:
   // ConcreteCommand& operator=(ConcreteCommand &) = default; // to prevent slicing
   // ConcreteCommand(const ConcreteCommand&) = default; // to prevent slicing
   /*
   The ConcreteCommand
   takes a reference to a Receiver */
   // object in its constructor.
   ConcreteCommand(Receiver &receiver)
       : receiver_(receiver)
   {
   }

   // The execute method calls the action on the Receiver.
   void Execute() const
   {
      receiver_.perform_action();
   }
};

/*
4. Invoker
----------
The invoker is responsible for triggering the execution of commands.
It holds references to the commands and can execute them.
It acts as an intermediary between the sender (client) and the receiver,
ensuring that the sender remains decoupled from the receiver.
*/
class Invoker
{
   reference_wrapper<Command> command_;

public:
   Invoker(reference_wrapper<Command> cmd) : command_{cmd} {}

   void setCommand(reference_wrapper<Command> cmd) { command_ = cmd; } // design flaw
   /*
   vector<Base&> v{}; won't compile
   vector<string&> won't compile either
   The elements of std::vector must be assignable, 
   whereas references can’t be reassigned, but only initialised
   One Solution: pointers
   */
   void executeCommand() { command_.get().Execute(); }
};

int design_pattern_command_3() // ROOT macro
// int main(int argc, char const *argv[]) // c++ compiler
{
   /* ref version w/o pointers */
	cout<<"------------------------"<<endl;
   Receiver receiver1{"Extract"};
   ConcreteCommand concreteCommand{receiver1};
   Invoker invoker{concreteCommand}; // ctor; arg == ref cmd
   invoker.executeCommand();

   Receiver receiver2{"Transform"}; // another pay-load
   ConcreteCommand concreteCommand2{receiver2};
   invoker.setCommand(concreteCommand2); // method; arg == ref cmd
   invoker.executeCommand();

   Receiver receiver3{"Load"}; // another pay-load
   ConcreteCommand concreteCommand3{receiver3};
   invoker.setCommand(concreteCommand3); // method; arg == ref cmd
   invoker.executeCommand();


	// A container of Commands 
	cout<<"------------------------"<<endl;
	vector<reference_wrapper<Command>> v1{};
	v1.push_back(concreteCommand);
	v1.push_back(concreteCommand2);
	v1.push_back(concreteCommand3);
	for(auto i:v1)
		i.get().Execute();

   return 0;
}
