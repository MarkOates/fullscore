

#include <fullscore/UI/PlotterList/Actions/MoveCursorDown.hpp>

#include <fullscore/UI/PlotterList/Widget.hpp>
#include <fullscore/UI/PlotterList/Actions.hpp>


namespace UI::PlotterList::Actions
{


MoveCursorDown::MoveCursorDown(UI::PlotterList::Widget *widget)
   : ::Action::Base(MOVE_CURSOR_UP_ACTION_IDENTIFIER)
   , widget(widget)
{
}


MoveCursorDown::~MoveCursorDown()
{
}


bool MoveCursorDown::execute()
{
   if (!widget) throw std::runtime_error("Cannot move the cursor down because plotter_list widget is null");
   widget->move_cursor_down();
   return true;
}


} // UI::PlotterList::Actions


