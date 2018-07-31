



#include <fullscore/actions/DeleteStaffAction.h>

#include <fullscore/models/Grid.h>
#include <fullscore/Action.h>



Action::DeleteStaff::DeleteStaff(Grid *grid, int at_index)
   : Base(Action::DELETE_STAFF_ACTION_IDENTIFIER)
   , grid(grid)
   , at_index(at_index)
{}




Action::DeleteStaff::~DeleteStaff()
{}




bool Action::DeleteStaff::execute()
{
   if (!grid) return false;
   if (at_index < 0 || at_index >= grid->get_num_staves()) return false;

   grid->delete_staff(at_index);

   return true;
}




