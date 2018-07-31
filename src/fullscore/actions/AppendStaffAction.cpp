



#include <fullscore/actions/AppendStaffAction.h>

#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Grid.h>
#include <fullscore/Action.h>




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




