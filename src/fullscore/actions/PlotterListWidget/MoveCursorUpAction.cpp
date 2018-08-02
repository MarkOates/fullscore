

#include <fullscore/actions/PlotterListWidget/MoveCursorUpAction.hpp>

#include <fullscore/widgets/PlotterListWidget.hpp>
#include <fullscore/actions/PlotterListWidget/Actions.hpp>


namespace Action
{
namespace PlotterListWidget
{


MoveCursorUpAction::MoveCursorUpAction(::PlotterListWidget *plotter_list_widget)
   : ::Action::Base(Actions::PlotterListWidget::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
   , plotter_list_widget(plotter_list_widget)
{
}


MoveCursorUpAction::~MoveCursorUpAction()
{
}


bool MoveCursorUpAction::execute()
{
   if (!plotter_list_widget) throw std::runtime_error("Cannot move the cursor up because plotter_list_widget is null");
   plotter_list_widget->move_cursor_up();
   return true;
}


}
}


