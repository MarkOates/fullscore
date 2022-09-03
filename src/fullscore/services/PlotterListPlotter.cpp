

#include <fullscore/services/PlotterListPlotter.hpp>

#include <fullscore/models/Repositories/PlotterRepository.hpp>
#include <fullscore/models/plotters/Base.hpp>


PlotterListPlotter::PlotterListPlotter(PlotterListRepository *plotter_list)
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


