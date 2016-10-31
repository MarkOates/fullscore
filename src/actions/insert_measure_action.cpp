



#include <fullscore/actions/insert_measure_action.h>

#include <fullscore/models/measure_grid.h>




Action::InsertMeasure::InsertMeasure(MeasureGrid *measure_grid, int at_index)
   : Base("insert_measure")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::InsertMeasure::~InsertMeasure()
{}




bool Action::InsertMeasure::execute()
{
   if (!measure_grid) return false;
   if (at_index < 0 || at_index >= measure_grid->get_num_measures()) return false;

   measure_grid->insert_measure(at_index);

   return true;
}




