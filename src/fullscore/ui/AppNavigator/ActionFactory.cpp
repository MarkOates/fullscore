

#include <fullscore/UI/AppNavigator/ActionFactory.hpp>

#include <fullscore/UI/AppNavigator/Actions.hpp>

#include <fullscore/UI/AppNavigator/Actions/SayHello.hpp>



namespace UI::AppNavigator
{


Action::Base *ActionFactory::create_action(Widget *widget, std::string action_name)
{
   if (action_name == Actions::SAY_HELLO_ACTION_IDENTIFIER)
      return new Actions::SayHello();

   return nullptr;
}


} // namespace UI::AppNavigator


