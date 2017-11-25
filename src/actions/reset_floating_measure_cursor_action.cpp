


#include <fullscore/actions/reset_floating_measure_cursor_action.h>

#include <fullscore/models/floating_measure_cursor.h>
#include <fullscore/models/floating_measure.h>
#include <fullscore/action.h>



Action::ResetFloatingMeasureCursor::ResetFloatingMeasureCursor(FloatingMeasureCursor *floating_measure_cursor)
   : Base(Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER)
   , floating_measure_cursor(floating_measure_cursor)
{}



Action::ResetFloatingMeasureCursor::~ResetFloatingMeasureCursor()
{}



bool Action::ResetFloatingMeasureCursor::execute()
{
   if (!floating_measure_cursor) throw std::runtime_error("Cannot reset nullptr floating_measure_cursor");

   if (FloatingMeasure::get_num_pool_elements() != 0)
   {
      std::vector<FloatingMeasure *> floating_measures = FloatingMeasure::get_pool_elements();
      floating_measure_cursor->set_floating_measure_id(floating_measures[0]->get_id());
   }

   return true;
}



