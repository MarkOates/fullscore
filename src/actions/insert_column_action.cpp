



#include <fullscore/actions/insert_column_action.h>

#include <fullscore/models/measure_grid.h>




Action::InsertColumn::InsertColumn(MeasureGrid *measure_grid, int at_index)
   : Base("insert_column")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::InsertColumn::~InsertColumn()
{}




bool Action::InsertColumn::execute()
{
   if (!measure_grid) return false;
   if (at_index < 0 || at_index >= measure_grid->get_num_measures()) return false;

   measure_grid->insert_column(at_index);

   return true;
}




