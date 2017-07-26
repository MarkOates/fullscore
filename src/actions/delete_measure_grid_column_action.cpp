



#include <fullscore/actions/delete_measure_grid_column_action.h>

#include <fullscore/models/measure_grid.h>




Action::DeleteMeasureGridColumn::DeleteMeasureGridColumn(MeasureGrid *measure_grid, int at_index)
   : Base("delete_measure_grid_column")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::DeleteMeasureGridColumn::~DeleteMeasureGridColumn()
{}




bool Action::DeleteMeasureGridColumn::execute()
{
   if (!measure_grid) return false;
   if (at_index < 0 || at_index >= measure_grid->get_num_measures()) return false;

   measure_grid->delete_column(at_index);

   return true;
}



