

#include <fullscore/UI/PlotterEditor/ActionFactory.hpp>

#include <fullscore/UI/PlotterEditor/Actions.hpp>

#include <fullscore/UI/PlotterEditor/Actions/SayHello.hpp>



namespace UI::PlotterEditor
{


Action::Base *ActionFactory::create_action(Widget *widget, std::string action_name)
{
   if (action_name == Actions::SAY_HELLO_ACTION_IDENTIFIER)
      return new Actions::SayHello();

   return nullptr;
}


} // namespace UI::PlotterEditor


