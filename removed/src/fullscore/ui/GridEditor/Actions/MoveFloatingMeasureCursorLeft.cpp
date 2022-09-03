


#include <fullscore/UI/GridEditor/Actions/MoveFloatingMeasureCursorLeft.hpp>

#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/UI/GridEditor/Actions.hpp>


namespace UI::GridEditor::Actions
{


MoveFloatingMeasureCursorLeft::MoveFloatingMeasureCursorLeft(FloatingMeasureCursor *floating_measure_cursor)
   : ::Action::Base(MOVE_FLOATING_MEASURE_CURSOR_LEFT_IDENTIFIER)
   , floating_measure_cursor(floating_measure_cursor)
{}



MoveFloatingMeasureCursorLeft::~MoveFloatingMeasureCursorLeft()
{}



bool MoveFloatingMeasureCursorLeft::execute()
{
   if (!floating_measure_cursor) throw std::runtime_error("Cannot move the floating_measure_cursor left because it does not exist");

   FloatingMeasure *current_floating_measure = FloatingMeasure::find(floating_measure_cursor->get_floating_measure_id());
   if (!current_floating_measure) throw std::runtime_error("Cannot move the floating_measure_cursor left because it does not have a valid floating_measure_id");

   // store the current_floating_measure's id
   int current_floating_measure_id = current_floating_measure->get_id();

   // get a (sorted) list of the floating_measures in the current staff
   std::vector<FloatingMeasure *> staff_floating_measures = FloatingMeasure::find_in_staff(current_floating_measure->get_grid_coordinate().get_staff_id());

   // get the current_floating_measure's index position in the list
   int current_floating_measure_position = -1;
   for (int i=0; i<staff_floating_measures.size(); i++)
      if (staff_floating_measures[i]->get_id() == current_floating_measure_id) { current_floating_measure_position = i; break; }

   // if the index position was not found, something is wrong
   if (current_floating_measure_position == -1)
      throw std::runtime_error("Could not find the current_floating_measure's position in list of measures (this shouldn't happen)");

   // prevent moving the cursor when it is already at the front
   if (current_floating_measure_position == 0)
      throw std::runtime_error("Can't move the floating_measure_cursor to the left; it's already at the front.");

   // set the current_floating_measure_id of the cursor to the previous measure
   FloatingMeasure *previous_floating_measure = staff_floating_measures[current_floating_measure_position - 1];
   floating_measure_cursor->set_floating_measure_id(previous_floating_measure->get_id());

   return true;
}


} // namespace UI::GridEditor::Actions

