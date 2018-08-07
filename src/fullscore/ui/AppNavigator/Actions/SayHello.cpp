

#include <fullscore/UI/AppNavigator/Actions/SayHello.hpp>

#include <fullscore/UI/AppNavigator/Actions.hpp>
#include <iostream>


namespace UI::AppNavigator::Actions
{


SayHello::SayHello()
   : ::Action::Base(SAY_HELLO_ACTION_IDENTIFIER)
{}


SayHello::~SayHello()
{}


bool SayHello::execute()
{
   std::cout << "Hello! AppNavigator" << std::endl;

   return false;
}


} // namespace UI::AppNavigator::Actions


