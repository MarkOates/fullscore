


#include <fullscore/actions/set_reference_measure_action.h>

#include <fullscore/models/measures/reference.h>
#include <fullscore/models/measure_grid.h>



Action::SetReferenceMeasure::SetReferenceMeasure(MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("set_reference_measure")
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



Action::SetReferenceMeasure::~SetReferenceMeasure()
{}



bool Action::SetReferenceMeasure::execute()
{
   if (!measure_grid) throw std::runtime_error("Cannot set Measure::Reference on a nullptr measure_grid");

   Measure::Reference *new_reference_measure = new Measure::Reference(nullptr, -1, -1);

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



