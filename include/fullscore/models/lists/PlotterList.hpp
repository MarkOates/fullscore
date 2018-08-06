#pragma once


#include <vector>


namespace Plotter { class Base; }


class PlotterList
{
private:
   std::vector<Plotter::Base *> plotters;

public:
   int count() const;

   Plotter::Base *get(int index);
   std::vector<Plotter::Base *> get_list();
   std::vector<Plotter::Base *> &get_list_ref();
   bool insert(Plotter::Base *plotter, int index);
   bool erase(int index);
   bool append(Plotter::Base *plotter);
};


