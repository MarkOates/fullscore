


#include <fullscore/models/lists/PlotterList.hpp>



int PlotterList::count() const
{
   return plotters.size();
}



Plotter::Base *PlotterList::get(int index)
{
   if (index < 0 || index >= plotters.size()) return nullptr;

   Plotter::Base *plotter = plotters[index];
   if (!plotter) return nullptr;
   return plotter;
}



std::vector<Plotter::Base *> PlotterList::get_list()
{
   return plotters;
}



std::vector<Plotter::Base *> &PlotterList::get_list_ref()
{
   return plotters;
}



bool PlotterList::insert(Plotter::Base *plotter, int index)
{
   if (!plotter) return false;

   if (index < 0) index = 0;

   if (index >= (int)plotters.size()) return append(plotter);
   else plotters.insert(plotters.begin() + index, plotter);

   return true;
}



bool PlotterList::erase(int index)
{
   if (index < 0 || index >= (int)plotters.size()) return false;
   // TODO: Thinking a delete voice[index] should happen here
   plotters.erase(plotters.begin() + index);
   return true;
}



bool PlotterList::append(Plotter::Base *plotter)
{
   if (!plotter) return false;
   plotters.push_back(plotter);
   return true;
}



