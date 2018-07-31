

#include <fullscore/services/PlotterListPlotter.hpp>

#include <fullscore/models/lists/PlotterList.hpp>
#include <fullscore/models/plotters/Base.h>


PlotterListPlotter::PlotterListPlotter(PlotterList *plotter_list)
   : plotter_list(plotter_list)
{
}


PlotterListPlotter::~PlotterListPlotter()
{
}


void PlotterListPlotter::plot()
{
   for (auto &plotter : plotter_list->get_list_ref())
   {
      plotter->plot();
   }
}


