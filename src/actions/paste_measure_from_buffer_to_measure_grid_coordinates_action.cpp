


#include <fullscore/actions/paste_measure_from_buffer_to_measure_grid_coordinates_action.h>

#include <fullscore/models/measure_grid.h>



Action::PasteMeasureFromBufferToMeasureGridCoordinates::PasteMeasureFromBufferToMeasureGridCoordinates(Measure::Basic *yank_measure_buffer, MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("paste_measure_from_buffer_to_measure_grid_coordinates_action")
   , yank_measure_buffer(yank_measure_buffer)
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{
}



Action::PasteMeasureFromBufferToMeasureGridCoordinates::~PasteMeasureFromBufferToMeasureGridCoordinates()
{
}



bool Action::PasteMeasureFromBufferToMeasureGridCoordinates::execute()
{
   if (!yank_measure_buffer) throw std::runtime_error("Cannot paste to a nullptr measure_grid");
   if (!measure_grid) throw std::runtime_error("Cannot paste to a nullptr measure_grid");
   if (!measure_grid->in_grid_range(measure_x, staff_y)) throw std::runtime_error("Cannot paste a measure to coordinates outside the measure_grid");

   Measure::Base *destination_measure = measure_grid->get_measure(measure_x, staff_y);

   if (!destination_measure)
   {
      std::stringstream error_message;
      error_message << "Cannot paste notes into a nullptr measure located at (" << measure_x << ", " << staff_y << ")" << std::endl;
      throw std::runtime_error(error_message.str());
   }

   bool successfully_set = destination_measure->set_notes(yank_measure_buffer->get_notes_copy());
   if (!successfully_set)
   {
      std::stringstream error_message;
      error_message << "Could not set notes measure (type " << destination_measure->get_type() << ") located at (" << measure_x << ", " << staff_y << ")" << std::endl;
      throw std::runtime_error(error_message.str());
   }
   return true;
}



