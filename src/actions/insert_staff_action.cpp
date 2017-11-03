



#include <fullscore/actions/insert_staff_action.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/grid.h>




Action::InsertStaff::InsertStaff(Grid *grid, int at_index)
   : Base("insert_staff")
   , grid(grid)
   , at_index(at_index)
{}




Action::InsertStaff::~InsertStaff()
{}




bool Action::InsertStaff::execute()
{
   if (!grid) return false;
   if (at_index < 0 || at_index >= grid->get_num_staves()) return false;

   grid->insert_staff(new Staff::Instrument(), at_index);

   return true;
}




