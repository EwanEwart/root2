#include <iostream>
#include <string>
#include <memory>

using namespace std;
/*
1. Command Interface via Abstract Class
--------------------------------------
This is an interface or abstract class
that declares an Execute method,
defining the contract for concrete commands.
It ensures that all commands have a method to perform their actions.
*/
class Command {
public:
   virtual ~Command() {
   } 
   virtual void Execute() const = 0;
};
/*
2. Concrete Commands
--------------------
Concrete command classes
implement the Command interface and
inherit from the abstract class.
Each concrete command
encapsulates a specific action to be performed.
For example, you might have concrete commands
- to turn on lights,
- open files, or
- send messages.
*/
class SimpleCommand : public Command
{
private:
   string pay_load_;
public:
   // ctor
   explicit SimpleCommand(string pay_load)
   : pay_load_(pay_load)
   { 
   }
   void Execute() const override
   {
      cout
      << "SimpleCommand: See, I can do simple things like printing ("
      << this->pay_load_
      << ")"
      << endl
      ;
   }   
};
/*
Receiver
--------
The receiver is responsible for performing the actual work
when a command is executed.
It knows how to carry out the requested action.
For example, in a home automation system,
the receiver could be a “Light” object
that understands how to turn a light on and off.
*/
class Receiver
{
public:
   void ProcessTask_1(string const & pay_load)
   {
      cout<<"Receiver: Task 1 working on " << pay_load << "." << endl;
   }
   void ProcessTask_2(string const & pay_load)
   {
      cout<<"Receiver: Task 2 working on " << pay_load << "." << endl;
   }
};

class ComplexCommand : public Command
{
private:
   // worker
   shared_ptr<Receiver> receiver_;
   // context data
   string pay_load_1_;
   string pay_load_2_;
public:
   // ComplexCommand() = delete;
   ComplexCommand
   (
        shared_ptr<Receiver>const& receiver
      , string const& pay_load_1
      , string const& pay_load_2
   )
   : receiver_(receiver)
   , pay_load_1_(pay_load_1)
   , pay_load_2_(pay_load_2)
   {
   }
   void Execute() const override
   {
      cout<<"ComplexCommand: Complex processing should be delegated to Receiver objects."<<endl;
      this->receiver_->ProcessTask_1(this->pay_load_1_);
      this->receiver_->ProcessTask_2(this->pay_load_2_); // same receiver, different pay load
   }
};

/*
Invoker
-------
The invoker is responsible for triggering the execution of commands.
It holds references to the commands and can execute them.
It acts as an intermediary between the sender (client) and the receiver,
ensuring that the sender remains decoupled from the receiver.
*/
class Invoker 
{
private:
   shared_ptr<Command> on_start_;
   shared_ptr<Command> on_finish_;
public:
   ~Invoker() { }
   void SetOnStart(shared_ptr<Command> command)
   {
      this->on_start_ = command;
   }
   void SetOnFinish(shared_ptr<Command> command)
   {
      this->on_finish_ = command;
   }
   void DoSomethingImportant()
   {
      cout<<"Invoker: Does anybody want something to be done before I begin ?"<<endl;
      if(this->on_start_)
      {
         this->on_start_->Execute();
      }
      cout<<"Invoker: ... doing something really important ... "<<endl;
      cout<<"Invoker: Does anybody want sonething done after I finish ?"<<endl;
      if(this->on_finish_)
      {
         this->on_finish_->Execute();
      }
   }
};

// int design_pattern_command(int const ac, char * const av[])
int design_pattern_command()
// int main(int const ac, char * const av[])
{
   // resource allocation
   auto invoker  { make_shared<Invoker>()  };
   auto receiver { make_shared<Receiver>() };

   // invoker initialisation
   invoker->SetOnStart(make_shared<SimpleCommand>("pay_load : Welcome to the Command Design Pattern !"));
   invoker->SetOnFinish(make_shared<ComplexCommand>(receiver,"receiver pay_load 1","receiver pay_load 2"));

   // 
   invoker->DoSomethingImportant();

   return 0;
}

