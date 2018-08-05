

#include <fullscore/UI/ComponentTemplate/Actions/SayHello.hpp>

#include <fullscore/UI/ComponentTemplate/Actions.hpp>
#include <iostream>


namespace UI::ComponentTemplate::Actions
{


SayHello::SayHello()
   : ::Action::Base(SAY_HELLO_ACTION_IDENTIFIER)
{}


SayHello::~SayHello()
{}


bool SayHello::execute()
{
   std::cout << "Hello! ComponentTemplate" << std::endl;

   return false;
}


} // namespace UI::ComponentTemplate::Actions


