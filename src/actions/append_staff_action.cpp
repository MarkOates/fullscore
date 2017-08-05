



#include <fullscore/actions/append_staff_action.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/measure_grid.h>




Action::AppendStaff::AppendStaff(MeasureGrid *measure_grid)
   : Base("append_staff")
   , measure_grid(measure_grid)
{}




Action::AppendStaff::~AppendStaff()
{}




bool Action::AppendStaff::execute()
{
   if (!measure_grid) return false;

   measure_grid->append_staff(new Staff::Instrument(measure_grid->get_num_measures()));

   return false;
}




