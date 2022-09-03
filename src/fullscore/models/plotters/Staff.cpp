


#include <fullscore/models/plotters/Staff.hpp>

#include <fullscore/models/measures/Basic.hpp>
#include <fullscore/models/staves/Base.hpp>
#include <fullscore/models/Plotter.hpp>
#include <fullscore/models/Staff.hpp>
#include <fullscore/models/FloatingMeasure.hpp>



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



