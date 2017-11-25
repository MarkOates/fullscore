


#include <fullscore/actions/set_floating_measure_cursor_after_grid_cursor_action.h>

#include <fullscore/models/floating_measure_cursor.h>
#include <fullscore/models/grid_cursor.h>
#include <fullscore/action.h>



Action::SetFloatingMeasureCursorAfterGridCursor::SetFloatingMeasureCursorAfterGridCursor(GridCursor *grid_cursor, FloatingMeasureCursor *floating_measure_cursor)
   : Base(Action::SET_FLOATING_MEASURE_CURSOR_AFTER_GRID_CURSOR_ACTION_IDENTIFIER)
   , grid_cursor(grid_cursor)
   , floating_measure_cursor(floating_measure_cursor)
{}



Action::SetFloatingMeasureCursorAfterGridCursor::~SetFloatingMeasureCursorAfterGridCursor()
{}



bool Action::SetFloatingMeasureCursorAfterGridCursor::execute()
{
   if (!grid_cursor) throw std::runtime_error("Cannot set floating measure cursor after grid cursor with a nullptr grid_cursor");
   if (!floating_measure_cursor) throw std::runtime_error("Cannot set floating measure cursor after grid cursor with a nullptr floating_measure_cursor");

   // unimplemented
   return false;
}



