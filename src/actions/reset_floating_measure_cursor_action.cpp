


#include <fullscore/actions/reset_floating_measure_cursor_action.h>

#include <fullscore/models/floating_measure_cursor.h>
#include <fullscore/models/floating_measure.h>
#include <fullscore/action.h>



Action::ResetFloatingMeasureCursor::ResetFloatingMeasureCursor(FloatingMeasureCursor *floating_measure_cursor, int staff_id, int barline_num)
   : Base(Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER)
   , floating_measure_cursor(floating_measure_cursor)
   , staff_id(staff_id)
   , barline_num(barline_num)
{}



Action::ResetFloatingMeasureCursor::~ResetFloatingMeasureCursor()
{}



bool Action::ResetFloatingMeasureCursor::execute()
{
   if (!floating_measure_cursor) throw std::runtime_error("Cannot reset nullptr floating_measure_cursor");

   FloatingMeasure *found_floating_measure = FloatingMeasure::find_first_in_staff_after_barline(staff_id, barline_num);

   if (!found_floating_measure) floating_measure_cursor->clear_floating_measure_id();
   else floating_measure_cursor->set_floating_measure_id(found_floating_measure->get_id());

   return true;
}



