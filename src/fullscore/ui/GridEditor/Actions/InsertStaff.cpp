



#include <fullscore/UI/GridEditor/Actions/InsertStaff.hpp>

#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Grid.h>
#include <fullscore/UI/GridEditor/Actions.hpp>



namespace UI::GridEditor::Actions
{


InsertStaff::InsertStaff(Grid *grid, int at_index)
   : ::Action::Base(INSERT_STAFF_ACTION_IDENTIFIER)
   , grid(grid)
   , at_index(at_index)
{}




InsertStaff::~InsertStaff()
{}




bool InsertStaff::execute()
{
   if (!grid) return false;
   if (at_index < 0 || at_index >= grid->get_num_staves()) return false;

   grid->insert_staff(new Staff::Instrument(), at_index);

   return true;
}


} // namespace UI::GridEditor::Actions


