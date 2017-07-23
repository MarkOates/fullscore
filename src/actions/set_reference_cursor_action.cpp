


#include <fullscore/actions/set_reference_cursor_action.h>

#include <fullscore/models/measure_grid.h>
#include <fullscore/reference_cursor.h>



Action::SetReferenceCursor::SetReferenceCursor(ReferenceCursor *reference_cursor, MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("set_reference_cursor")
   , reference_cursor(reference_cursor)
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



bool Action::SetReferenceCursor::execute()
{
   return true;
}



