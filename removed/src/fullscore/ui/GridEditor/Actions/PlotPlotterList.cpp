

#include <fullscore/UI/GridEditor/Actions/PlotPlotterList.hpp>

#include <fullscore/models/lists/PlotterList.hpp>
#include <fullscore/services/PlotterListPlotter.hpp>
#include <fullscore/UI/GridEditor/Actions.hpp>


namespace UI::GridEditor::Actions
{

PlotPlotterList::PlotPlotterList(PlotterList *plotter_list)
   : ::Action::Base(PLOT_PLOTTER_LIST_ACTION_IDENTIFIER)
   , plotter_list(plotter_list)
{
}


PlotPlotterList::~PlotPlotterList()
{
}


bool PlotPlotterList::execute()
{
   PlotterListPlotter plotter_list_plotter(plotter_list);
   plotter_list_plotter.plot();
   return true;
}

} // namespace UI::GridEditor::Actions

