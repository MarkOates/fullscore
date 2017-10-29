


#include <fullscore/models/plotters/basic.h>

#include <fullscore/models/measures/plotted.h>
#include <fullscore/models/staves/base.h>
#include <fullscore/models/plotter.h>
#include <fullscore/models/grid.h>
#include <fullscore/models/floating_measure.h>



Plotter::Basic::Basic(Grid *grid, int barline_num, std::vector<Note> notes)
   : Base(Plotter::TYPE_IDENTIFIER_BASIC)
   , grid(grid)
   , barline_num(barline_num)
   , notes(notes)
{
}



Plotter::Basic::~Basic()
{
}



bool Plotter::Basic::plot()
{
   if (!grid) throw std::runtime_error("Cannot plot with a nullptr grid");

   for (unsigned i=0; i<grid->get_num_staves(); i++)
   {
      Staff::Base *staff = grid->get_staff(i);

      if (staff->is_type("instrument"))
      {
         int staff_id = staff->get_id();
         Measure::Base* plotted_measure = new Measure::Plotted(notes); // < this automatically adds the measure to the base
         new FloatingMeasure(GridCoordinate(grid, staff_id, barline_num), plotted_measure->get_id());
      }
   }

   return true;
}



