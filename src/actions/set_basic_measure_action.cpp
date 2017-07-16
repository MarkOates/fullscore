



#include <fullscore/actions/set_basic_measure_action.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/measure_grid.h>



Action::SetBasicMeasure::SetBasicMeasure(MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("set_basic_measure")
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}




Action::SetBasicMeasure::~SetBasicMeasure()
{}




bool Action::SetBasicMeasure::execute()
{
   if (!measure_grid) throw std::runtime_error("Cannot set Measure::Basic on a nullptr measure_grid");

   Measure::Basic *new_basic_measure = new Measure::Basic();

   bool measure_set_successfully = measure_grid->set_measure(measure_x, staff_y, new_basic_measure);

   if (!measure_set_successfully)
   {
      delete new_basic_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::Basic the measure in the measure grid at (" << measure_x << ", " << staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}




