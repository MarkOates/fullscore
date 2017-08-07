



#include <fullscore/actions/insert_column_action.h>

#include <fullscore/models/grid.h>




Action::InsertColumn::InsertColumn(MeasureGrid *grid, int at_index)
   : Base("insert_column")
   , grid(grid)
   , at_index(at_index)
{}




Action::InsertColumn::~InsertColumn()
{}




bool Action::InsertColumn::execute()
{
   if (!grid) return false;
   if (at_index < 0 || at_index >= grid->get_num_measures()) return false;

   grid->insert_column(at_index);

   return true;
}




