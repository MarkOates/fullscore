



#include <fullscore/actions/append_staff_action.h>

#include <fullscore/models/staves/instrument.h>
#include <fullscore/models/grid.h>
#include <fullscore/action.h>




Action::AppendStaff::AppendStaff(Grid *grid)
   : Base(Action::APPEND_STAFF_ACTION_IDENTIFIER)
   , grid(grid)
{}




Action::AppendStaff::~AppendStaff()
{}




bool Action::AppendStaff::execute()
{
   if (!grid) return false;

   grid->append_staff(new Staff::Instrument());

   return false;
}




