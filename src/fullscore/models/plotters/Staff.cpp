


#include <fullscore/models/plotters/Staff.hpp>

#include <allegro_flare/useful.h>
#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/staves/Base.h>
#include <fullscore/models/Plotter.h>
#include <fullscore/models/Staff.h>
#include <fullscore/models/FloatingMeasure.h>



Plotter::Staff::Staff(std::vector<int> staff_ids, int barline_num, std::vector<Note> notes)
   : Base(Plotter::TYPE_IDENTIFIER_BASIC)
   , staff_ids(staff_ids)
   , barline_num(barline_num)
   , notes(notes)
{
}



Plotter::Staff::~Staff()
{
}



bool Plotter::Staff::plot()
{
   for (auto &staff_id : staff_ids)
   {
      ::Staff::Base *staff = ::Staff::find(staff_id);
      if (!staff)
      {
         throw std::runtime_error("[Plotter::Staff] Cannot find staff");
      }
      if (!staff->is_type("instrument"))
      {
         throw std::runtime_error("[Plotter::Staff] Cannot plot to non-instrument staff");
      }

      Measure::Base* plotted_measure = new Measure::Basic(notes); // < this automatically adds the measure to the base
      new FloatingMeasure(GridCoordinate(staff_id, {barline_num, { 0 }}), plotted_measure->get_id());
   }

   return true;
}



