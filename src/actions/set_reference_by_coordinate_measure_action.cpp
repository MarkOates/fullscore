


#include <fullscore/actions/set_reference_by_coordinate_measure_action.h>

#include <fullscore/models/measures/reference_by_coordinate.h>
#include <fullscore/models/grid.h>



Action::SetReferenceByCoordinateMeasure::SetReferenceByCoordinateMeasure(Grid *grid, int measure_x, int staff_y, Grid *referenced_grid, int referenced_measure_x, int referenced_staff_y)
   : Base("set_reference_by_coordinate_measure")
   , grid(grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
   , referenced_grid(referenced_grid)
   , referenced_measure_x(referenced_measure_x)
   , referenced_staff_y(referenced_staff_y)
{}



Action::SetReferenceByCoordinateMeasure::~SetReferenceByCoordinateMeasure()
{}



bool Action::SetReferenceByCoordinateMeasure::execute()
{
   if (!grid) throw std::runtime_error("Cannot set Measure::ReferenceByCoordinate on a nullptr grid");
   // this next line has been commented out because it is probably not needed
   //if (!referenced_grid) throw std::runtime_error("Cannot set Measure::Reference on a nullptr reference_grid");

   if (grid == referenced_grid && measure_x == referenced_measure_x && staff_y == referenced_staff_y)
      throw std::runtime_error("a Measure::ReferenceByCoordinate cannot reference itself");

   Measure::ReferenceByCoordinate *new_reference_measure = new Measure::ReferenceByCoordinate(referenced_grid, referenced_measure_x, referenced_staff_y);

   bool measure_set_successfully = grid->set_measure(measure_x, staff_y, new_reference_measure);

   if (!measure_set_successfully)
   {
      delete new_reference_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::ReferenceByCoordinate the measure in the measure grid at (" << measure_x << ", " << staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}



