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
      << this->payload_
      << ")"
      << endl
      ;
   }   
};


