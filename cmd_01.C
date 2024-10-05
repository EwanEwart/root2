/*

https://trussel.ch/cpp/design%20patterns/2020/10/18/command-pattern.html

C++ Design Patterns: A Modern Command Pattern
This is not the Gang of Four
The Command Pattern solved in a different way.
Send commands to a possibly remote application.
Design : easily testable & maintainable.

Goal: control a LightBulb
*/

// fictitious / mock LightBulb HW class
struct LightBulb
{
   LightBulb(string name = "n/a")
       : name_{move(name)}
   {
   }

   void set_brightness(unsigned value)
   {
      cout
          << "LightBulb(" << name_ << ')'
          << " set brightness to value " << value
          << endl;
   }
   void set_colour(unsigned red = 0, unsigned green = 0, unsigned blue = 0)
   {
      cout
          << "LightBulb(" << name_ << ')'
          << " set colour to RGB(" << red << ',' << green << ',' << blue << ')'
          << endl;
   }
   string &get_name()
   {
      return name_;
   }
   void set_name(string const &name)
   {
      name_ = name;
   }

   string name_{""};
};
/*
perspective sw, which controlls LightBulb

To do ...
1. receive the command from a communications interface
2. deserialise the command
3. pass the command to the HW, here the lightBulb, call a function of the HW class
*/

// The Commands
/*
Since C++17
the visitor pattern built into STL:
std::variant & std::visit
*/

namespace cmd
{
   struct SetBrightness
   {
      unsigned value{};
   };
   struct SetColour
   {
      unsigned r{};
      unsigned g{};
      unsigned b{};
   };
   using Command = variant<SetBrightness, SetColour>;

   /*
   An instance of "std::variant" holds "one" of its template types.
   So it is a great way to store "unrelated types" like our command structs.

   We then only need a "visitable object".
   We need an action for every type the variant can hold:
   */

   struct CommandExecutor
   {

      CommandExecutor(LightBulb &bulb)
          : bulb_{bulb}
      {
      }
      // action
      void operator()(SetBrightness const &cmd)
      {
         bulb_.set_brightness(cmd.value);
      }
      // action
      void operator()(SetColour const &cmd)
      {
         bulb_.set_colour(cmd.r, cmd.g, cmd.b);
      }

   private:
      LightBulb &bulb_;
   };

} // namespace cmd

/*
https://json.nlohmann.me/
Define simple POD structs that represent your commands
and use std::variant to pass them around.

Define a visitor object
that performs different actions
based on the actual value of the std::variant

To give a more complete example
we will also look at the communication and serialization steps
mentioned above.

Deserialize it!

On the communication interface, which we will define bellow,
we will receive the commands in a certain format / protocol
and we need to parse these messages
into our command representation above.

For this example I will use JSON.
JSON is in my opinion a very good starting point
for machine to machine communication,
because it is also human readable and therefore easy to debug.
Most of the time its performance is also good enough
for sending small data like the here mentioned commands.

I decided to use nlohmann/json for this example...
*/
#include <nlohmann/json.hpp>
using json = nlohmann::json;
namespace cmd
{

   inline void to_json(json &j, const SetBrightness &cmd)
   {
      j = json{{"brightness", cmd.value}};
   }

   inline void from_json(const json &j, SetBrightness &cmd)
   {
      j.at("brightness").get_to(cmd.value);
   }

   inline void to_json(json &j, const SetColour &cmd)
   {
      j = json{{"red", cmd.r}, {"green", cmd.g}, {"blue", cmd.b}};
   }

   inline void from_json(const json &j, SetColour &cmd)
   {
      j.at("red").get_to(cmd.r);
      j.at("green").get_to(cmd.g);
      j.at("blue").get_to(cmd.b);
   }

   inline Command deserialize(const json &j)
   {
      Command ret;
      const auto type = j.at("command_type").get<std::string>();
      if (type == "set_brightness")
      {
         ret = j.at("command_arguments").get<SetBrightness>();
      }
      else if (type == "set_color")
      {
         ret = j.at("command_arguments").get<SetColour>();
      }
      else
      {
         throw std::runtime_error("Could not deserialize json command " + j.dump());
      }
      return ret;
   }

} // namespace cmd

// C-macro, entry point
void cmd_01()
{
   cout << "test bed cmd pattern loaded" << endl;
}
