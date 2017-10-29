


#include <fullscore/actions/set_stack_measure_action.h>

#include <fullscore/models/measures/stack.h>
#include <fullscore/models/grid.h>



Action::SetStackMeasure::SetStackMeasure(Grid *grid, int measure_x, int staff_y)
   : Base("set_stack_measure")
   , grid(grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



Action::SetStackMeasure::~SetStackMeasure()
{}



bool Action::SetStackMeasure::execute()
{
   if (!grid) throw std::runtime_error("Cannot set Measure::Stack on a nullptr grid");

   Measure::Stack *new_stack_measure = new Measure::Stack();

   bool measure_set_successfully = grid->set_measure(measure_x, staff_y, new_stack_measure);

   if (!measure_set_successfully)
   {
      delete new_stack_measure;
      std::stringstream error_message;
      error_message << "Could not set a Measure::Stack the measure in the measure grid at (" << measure_x << ", " << staff_y << ")";
      throw std::runtime_error(error_message.str());
   }

   return true;
}



