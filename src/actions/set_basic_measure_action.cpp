


#include <fullscore/actions/set_basic_measure_action.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/grid.h>



Action::SetBasicMeasure::SetBasicMeasure(Grid *grid, int measure_x, int staff_y)
   : Base("set_basic_measure")
   , grid(grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



Action::SetBasicMeasure::~SetBasicMeasure()
{}



bool Action::SetBasicMeasure::execute()
{
   if (!grid) throw std::runtime_error("Cannot set Measure::Basic on a nullptr grid");

   Measure::Basic *new_basic_measure = new Measure::Basic();

   bool measure_set_successfully = grid->set_measure(measure_x, staff_y, new_basic_measure);

   if (!measure_set_successfully)
   {
      delete new_basic_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::Basic the measure in the measure grid at (" << measure_x << ", " << staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}



