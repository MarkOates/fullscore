


#include <fullscore/actions/set_reference_cursor_action.h>

#include <fullscore/models/measure_grid.h>
#include <fullscore/models/reference_cursor.h>



Action::SetReferenceCursor::SetReferenceCursor(ReferenceCursor *reference_cursor, MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("set_reference_cursor")
   , reference_cursor(reference_cursor)
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



bool Action::SetReferenceCursor::execute()
{
   if (!reference_cursor) throw std::invalid_argument("Cannot set reference cursor on a nullptr reference_cursor");

   reference_cursor->set_position(measure_grid, measure_x, staff_y);

   if (!reference_cursor->is_valid()) throw std::runtime_error("Recently set reference cursor is now invalid");

   return true;
}



