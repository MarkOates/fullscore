


#include <fullscore/models/plotters/Basic.hpp>

#include <fullscore/models/measures/Basic.hpp>
#include <fullscore/models/staves/Base.hpp>
#include <fullscore/models/Plotter.hpp>
#include <fullscore/models/Grid.hpp>
#include <fullscore/models/Repositories/FloatingMeasureRepository.hpp>



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
         Measure::Base* plotted_measure = new Measure::Basic(notes); // < this automatically adds the measure to the base
         new FloatingMeasureRepository(GridCoordinate(staff_id, {barline_num, { 0 }}), plotted_measure->get_id());
      }
   }

   return true;
}



