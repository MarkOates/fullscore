



#include <fullscore/actions/delete_measure_action.h>

#include <fullscore/models/measure_grid.h>




Action::DeleteMeasure::DeleteMeasure(MeasureGrid *measure_grid, int at_index)
   : Base("delete_measure")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::DeleteMeasure::~DeleteMeasure()
{}




bool Action::DeleteMeasure::execute()
{
   if (!measure_grid) return false;
   if (at_index < 0 || at_index >= measure_grid->get_num_measures()) return false;

   // unimplemented
   return false;
}




