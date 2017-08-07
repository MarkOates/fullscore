



#include <fullscore/actions/append_staff_action.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/grid.h>




Action::AppendStaff::AppendStaff(Grid *grid)
   : Base("append_staff")
   , grid(grid)
{}




Action::AppendStaff::~AppendStaff()
{}




bool Action::AppendStaff::execute()
{
   if (!grid) return false;

   grid->append_staff(new Staff::Instrument(grid->get_num_measures()));

   return false;
}




