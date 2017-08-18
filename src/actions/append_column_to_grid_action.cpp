



#include <fullscore/actions/append_column_to_grid_action.h>

#include <fullscore/models/grid.h>
#include <fullscore/action.h>




Action::AppendColumnToGrid::AppendColumnToGrid(Grid *grid)
   : Base(APPEND_COLUMN_TO_GRID_ACTION_IDENTIFIER)
   , grid(grid)
{}




Action::AppendColumnToGrid::~AppendColumnToGrid()
{}




bool Action::AppendColumnToGrid::execute()
{
   if (!grid) return false;

   grid->append_measure();

   return false;
}




