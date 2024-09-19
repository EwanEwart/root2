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

#define invoker_pointer_cmd
#undef invoker_pointer_cmd

#ifdef invoker_pointer_cmd
// ptr command
class Invoker
{
   Command *command_;

public:
   void setCommand(Command *cmd) { command_ = cmd; }
   void executeCommand() { command_->Execute(); }
};
#else
// ref command
class Invoker
{
   Command &command_;

public:
   Invoker(Command &cmd) : command_{cmd} {}
   void setCommand(Command const &cmd) { command_ = cmd; }
   void executeCommand() { command_.Execute(); }
};
#endif



// int design_pattern_command_2() // ROOT
int main(int argc, char const *argv[]) // code_insiders
{
   Receiver receiver1{"Launch Rocket"};
   ConcreteCommand concreteCommand{receiver1};
#ifdef invoker_pointer_cmd
   Invoker invoker{};                    // ptr
   invoker.setCommand(&concreteCommand); // ptr
#else
   Invoker invoker{concreteCommand};           // ref
#endif
   invoker.executeCommand();

   Receiver receiver2{"Land Rocket"}; // another pay-load
   ConcreteCommand concreteCommand2{receiver2};
#ifdef invoker_pointer_cmd
   invoker.setCommand(&concreteCommand2); // ptr / reuse invoker
#else
   invoker.setCommand(concreteCommand2); // ref
#endif
   invoker.executeCommand();

   return 0;
}
