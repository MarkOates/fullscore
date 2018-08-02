

#include <fullscore/UI/PlotterList/Actions/MoveCursorUp.hpp>

#include <fullscore/UI/PlotterList/Widget.hpp>
#include <fullscore/UI/PlotterList/Actions.hpp>


namespace UI::PlotterList::Actions
{


MoveCursorUp::MoveCursorUp(UI::PlotterList::Widget *plotter_list_widget)
   : ::Action::Base(MOVE_CURSOR_UP_ACTION_IDENTIFIER)
   , plotter_list_widget(plotter_list_widget)
{
}


MoveCursorUp::~MoveCursorUp()
{
}


bool MoveCursorUp::execute()
{
   if (!plotter_list_widget) throw std::runtime_error("Cannot move the cursor up because plotter_list_widget is null");
   plotter_list_widget->move_cursor_up();
   return true;
}


}


