


#include <fullscore/actions/set_reference_by_coordinate_measure_action.h>

#include <fullscore/models/measures/reference_by_coordinate.h>
#include <fullscore/models/grid.h>



Action::SetReferenceByCoordinateMeasure::SetReferenceByCoordinateMeasure(Grid *destination_grid, int destination_measure_x, int destination_staff_y, Grid *referenced_grid, int referenced_measure_x, int referenced_staff_y)
   : Base("set_reference_by_coordinate_measure")
   , destination_grid(destination_grid)
   , destination_measure_x(destination_measure_x)
   , destination_staff_y(destination_staff_y)
   , referenced_grid(referenced_grid)
   , referenced_measure_x(referenced_measure_x)
   , referenced_staff_y(referenced_staff_y)
{}



Action::SetReferenceByCoordinateMeasure::~SetReferenceByCoordinateMeasure()
{}



bool Action::SetReferenceByCoordinateMeasure::execute()
{
   if (!destination_grid) throw std::runtime_error("Cannot set Measure::ReferenceByCoordinate on a nullptr grid");

   if (destination_grid == referenced_grid && destination_measure_x == referenced_measure_x && destination_staff_y == referenced_staff_y)
      throw std::runtime_error("a Measure::ReferenceByCoordinate cannot reference itself");

   Measure::ReferenceByCoordinate *new_reference_measure = new Measure::ReferenceByCoordinate(referenced_grid, referenced_measure_x, referenced_staff_y);

   bool measure_set_successfully = destination_grid->set_measure(destination_measure_x, destination_staff_y, new_reference_measure);

   if (!measure_set_successfully)
   {
      delete new_reference_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::ReferenceByCoordinate the measure in the grid at (" << destination_measure_x << ", " << destination_staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}



