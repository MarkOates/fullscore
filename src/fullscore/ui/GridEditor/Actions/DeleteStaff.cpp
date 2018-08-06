



#include <fullscore/UI/GridEditor/Actions/DeleteStaff.hpp>

#include <fullscore/models/Grid.h>
#include <fullscore/UI/GridEditor/Actions.hpp>


namespace UI::GridEditor::Actions
{


DeleteStaff::DeleteStaff(Grid *grid, int at_index)
   : ::Action::Base(DELETE_STAFF_ACTION_IDENTIFIER)
   , grid(grid)
   , at_index(at_index)
{}




DeleteStaff::~DeleteStaff()
{}




bool DeleteStaff::execute()
{
   if (!grid) return false;
   if (at_index < 0 || at_index >= grid->get_num_staves()) return false;

   grid->delete_staff(at_index);

   return true;
}


} // namespace UI::GridEditor::Actions


