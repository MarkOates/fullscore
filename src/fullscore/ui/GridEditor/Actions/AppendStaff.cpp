



#include <fullscore/UI/GridEditor/Actions/AppendStaff.hpp>

#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Grid.h>
#include <fullscore/UI/GridEditor/Actions.hpp>



namespace UI::GridEditor::Actions
{


AppendStaff::AppendStaff(Grid *grid)
   : ::Action::Base(APPEND_STAFF_ACTION_IDENTIFIER)
   , grid(grid)
{}




AppendStaff::~AppendStaff()
{}




bool AppendStaff::execute()
{
   if (!grid) return false;

   grid->append_staff(new Staff::Instrument());

   return false;
}


} // namespace UI::GridEditor::Actions


