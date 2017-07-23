


#include <fullscore/actions/delete_measure_action.h>

#include <fullscore/models/measure_grid.h>



Action::DeleteMeasure::DeleteMeasure(MeasureGrid *measure_grid, int measure_x, int staff_y)
   : Base("delete_measure")
   , measure_grid(measure_grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



bool Action::DeleteMeasure::execute()
{
   if (!measure_grid) std::runtime_error("Cannot delete a measure on a nullptr measure_grid");

   return measure_grid->delete_measure(measure_x, staff_y);
}



