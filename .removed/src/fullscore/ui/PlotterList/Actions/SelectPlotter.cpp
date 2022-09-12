

#include <fullscore/UI/PlotterList/Actions/SelectPlotter.hpp>

#include <fullscore/UI/PlotterList/Widget.hpp>
#include <fullscore/UI/PlotterList/Actions.hpp>


namespace UI::PlotterList::Actions
{


SelectPlotter::SelectPlotter(UI::PlotterList::Widget *plotter_list_widget)
   : ::Action::Base(SELECT_PLOTTER_ACTION_IDENTIFIER)
   , plotter_list_widget(plotter_list_widget)
{
}


SelectPlotter::~SelectPlotter()
{
}


bool SelectPlotter::execute()
{
   if (!plotter_list_widget) throw std::runtime_error("Cannot SelectPlotter because widget is null");

   throw std::runtime_error("SelectPlotter not implemented");

   return true;
}


}


