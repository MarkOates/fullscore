

#include <fullscore/factories/PlotterListWidgetActionFactory.hpp>
#include <fullscore/actions/PlotterListWidget/Actions.hpp>
#include <fullscore/actions/PlotterListWidget/MoveCursorUpAction.hpp>
#include <fullscore/actions/PlotterListWidget/MoveCursorDownAction.hpp>
#include <fullscore/actions/PlotterListWidget/SelectPlotterAction.hpp>


#include <iostream>

Action::Base *PlotterListWidgetActionFactory::create_action(PlotterListWidget *plotter_list_widget, std::string action_name)
{
   if (action_name == Actions::PlotterListWidget::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
      return new Action::PlotterListWidget::MoveCursorUpAction(plotter_list_widget);
   else if (action_name == Actions::PlotterListWidget::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER)
      return new Action::PlotterListWidget::MoveCursorDownAction(plotter_list_widget);
   else if (action_name == Actions::PlotterListWidget::SELECT_PLOTTER_ACTION_IDENTIFIER)
      throw std::runtime_error("SELECT_PLOTTER_ACTION_IDENTIFIER not implemented");
}


