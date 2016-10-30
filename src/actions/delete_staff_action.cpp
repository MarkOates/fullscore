



#include <fullscore/actions/delete_staff_action.h>

#include <fullscore/models/measure_grid.h>




Action::DeleteStaff::DeleteStaff(MeasureGrid *measure_grid, int at_index)
   : Base("delete_staff")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::DeleteStaff::~DeleteStaff()
{}




bool Action::DeleteStaff::execute()
{
   if (!measure_grid) return false;
   if (at_index < 0 || at_index >= measure_grid->get_num_staves()) return false;

   measure_grid->delete_staff(at_index);

   return true;
}




