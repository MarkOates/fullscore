

#include <fullscore/UI/GridEditor/Actions/PlotPlotterList.hpp>

#include <fullscore/models/lists/PlotterList.hpp>
#include <fullscore/services/PlotterListPlotter.hpp>
#include <fullscore/UI/GridEditor/Actions.hpp>


Action::PlotPlotterList::PlotPlotterList(PlotterList *plotter_list)
   : ::Action::Base(Action::PLOT_PLOTTER_LIST_ACTION_IDENTIFIER)
   , plotter_list(plotter_list)
{
}


Action::PlotPlotterList::~PlotPlotterList()
{
}


bool Action::PlotPlotterList::execute()
{
   PlotterListPlotter plotter_list_plotter(plotter_list);
   plotter_list_plotter.plot();
   return true;
}


