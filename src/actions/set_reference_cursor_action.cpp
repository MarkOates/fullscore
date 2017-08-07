


#include <fullscore/actions/set_reference_cursor_action.h>

#include <fullscore/models/grid.h>
#include <fullscore/models/reference_cursor.h>



Action::SetReferenceCursor::SetReferenceCursor(ReferenceCursor *reference_cursor, Grid *grid, int measure_x, int staff_y)
   : Base("set_reference_cursor")
   , reference_cursor(reference_cursor)
   , grid(grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



bool Action::SetReferenceCursor::execute()
{
   if (!reference_cursor) throw std::invalid_argument("Cannot set reference cursor on a nullptr reference_cursor");

   reference_cursor->set_position(grid, measure_x, staff_y);

   if (!reference_cursor->is_valid()) throw std::runtime_error("Recently set reference cursor is now invalid");

   return true;
}



