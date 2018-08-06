

#include <fullscore/UI/ComponentTemplate/ActionFactory.hpp>

#include <fullscore/UI/ComponentTemplate/Actions.hpp>

#include <fullscore/UI/ComponentTemplate/Actions/SayHello.hpp>



namespace UI::ComponentTemplate
{


Action::Base *ActionFactory::create_action(Widget *widget, std::string action_name)
{
   if (action_name == Actions::SAY_HELLO_ACTION_IDENTIFIER)
      return new Actions::SayHello();

   return nullptr;
}


} // namespace UI::ComponentTemplate


