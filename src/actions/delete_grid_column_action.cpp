



#include <fullscore/actions/delete_grid_column_action.h>

#include <fullscore/models/grid.h>




Action::DeleteMeasureGridColumn::DeleteMeasureGridColumn(MeasureGrid *grid, int at_index)
   : Base("delete_grid_column")
   , grid(grid)
   , at_index(at_index)
{}




Action::DeleteMeasureGridColumn::~DeleteMeasureGridColumn()
{}




bool Action::DeleteMeasureGridColumn::execute()
{
   if (!grid) return false;
   if (at_index < 0 || at_index >= grid->get_num_measures()) return false;

   grid->delete_column(at_index);

   return true;
}




