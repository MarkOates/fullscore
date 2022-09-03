


#include <fullscore/models/Repositories/PlotterRepository.hpp>



int PlotterRepository::count() const
{
   return plotters.size();
}



Plotter::Base *PlotterRepository::get(int index)
{
   if (index < 0 || index >= plotters.size()) return nullptr;

   Plotter::Base *plotter = plotters[index];
   if (!plotter) return nullptr;
   return plotter;
}



std::vector<Plotter::Base *> PlotterRepository::get_list()
{
   return plotters;
}



std::vector<Plotter::Base *> &PlotterRepository::get_list_ref()
{
   return plotters;
}



bool PlotterRepository::insert(Plotter::Base *plotter, int index)
{
   if (!plotter) return false;

   if (index < 0) index = 0;

   if (index >= (int)plotters.size()) return append(plotter);
   else plotters.insert(plotters.begin() + index, plotter);

   return true;
}



bool PlotterRepository::erase(int index)
{
   if (index < 0 || index >= (int)plotters.size()) return false;
   // TODO: Thinking a delete voice[index] should happen here
   plotters.erase(plotters.begin() + index);
   return true;
}



bool PlotterRepository::append(Plotter::Base *plotter)
{
   if (!plotter) return false;
   plotters.push_back(plotter);
   return true;
}



