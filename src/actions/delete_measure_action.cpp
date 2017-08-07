


#include <fullscore/actions/delete_measure_action.h>

#include <fullscore/models/grid.h>



Action::DeleteMeasure::DeleteMeasure(MeasureGrid *grid, int measure_x, int staff_y)
   : Base("delete_measure")
   , grid(grid)
   , measure_x(measure_x)
   , staff_y(staff_y)
{}



bool Action::DeleteMeasure::execute()
{
   if (!grid) std::runtime_error("Cannot delete a measure on a nullptr grid");

   return grid->delete_measure(measure_x, staff_y);
}



