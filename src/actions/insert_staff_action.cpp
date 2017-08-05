



#include <fullscore/actions/insert_staff_action.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/measure_grid.h>




Action::InsertStaff::InsertStaff(MeasureGrid *measure_grid, int at_index)
   : Base("insert_staff")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::InsertStaff::~InsertStaff()
{}




bool Action::InsertStaff::execute()
{
   if (!measure_grid) return false;
   if (at_index < 0 || at_index >= measure_grid->get_num_staves()) return false;

   measure_grid->insert_staff(new Staff::Instrument(measure_grid->get_num_measures()), at_index);

   return true;
}




