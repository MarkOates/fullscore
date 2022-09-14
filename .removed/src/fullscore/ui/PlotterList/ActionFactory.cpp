

#include <fullscore/UI/PlotterList/ActionFactory.hpp>

#include <fullscore/UI/PlotterList/Actions.hpp>
#include <fullscore/UI/PlotterList/Actions/MoveCursorUp.hpp>
#include <fullscore/UI/PlotterList/Actions/MoveCursorDown.hpp>
#include <fullscore/UI/PlotterList/Actions/SelectPlotter.hpp>


namespace UI::PlotterList
{


Action::Base *ActionFactory::create_action(Widget *widget, std::string action_name)
{
   if (action_name == UI::PlotterList::Actions::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
      return new UI::PlotterList::Actions::MoveCursorUp(widget);
   else if (action_name == UI::PlotterList::Actions::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER)
      return new UI::PlotterList::Actions::MoveCursorDown(widget);
   else if (action_name == UI::PlotterList::Actions::SELECT_PLOTTER_ACTION_IDENTIFIER)
      return new UI::PlotterList::Actions::SelectPlotter(widget);

   throw std::runtime_error("Unrecognized action name in PlotterList::ActionFactory");
}


} // namespace UI::PlotterList


