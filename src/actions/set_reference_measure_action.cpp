


#include <fullscore/actions/set_reference_measure_action.h>

#include <fullscore/models/measures/reference.h>
#include <fullscore/models/measure_grid.h>



Action::SetReferenceMeasure::SetReferenceMeasure(MeasureGrid *measure_grid, int measure_x, int staff_y, MeasureGrid *referenced_measure_grid, int referenced_measure_x, int referenced_staff_y)
   : Base("set_reference_measure")
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
   , referenced_measure_grid(referenced_measure_grid)
   , referenced_measure_x(referenced_measure_x)
   , referenced_staff_y(referenced_staff_y)
{}



Action::SetReferenceMeasure::~SetReferenceMeasure()
{}



bool Action::SetReferenceMeasure::execute()
{
   if (!measure_grid) throw std::runtime_error("Cannot set Measure::Reference on a nullptr measure_grid");
   // this next line has been commented out because it is probably not needed
   //if (!referenced_measure_grid) throw std::runtime_error("Cannot set Measure::Reference on a nullptr reference_measure_grid");

   if (measure_grid == referenced_measure_grid && measure_x == referenced_measure_x && staff_y == referenced_staff_y)
      throw std::runtime_error("a Measure::Reference cannot reference itself");

   Measure::Reference *new_reference_measure = new Measure::Reference(referenced_measure_grid, referenced_measure_x, referenced_staff_y);

   bool measure_set_successfully = measure_grid->set_measure(measure_x, staff_y, new_reference_measure);

   if (!measure_set_successfully)
   {
      delete new_reference_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::Reference the measure in the measure grid at (" << measure_x << ", " << staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}



