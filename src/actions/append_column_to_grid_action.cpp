



#include <fullscore/actions/append_column_to_grid_action.h>

#include <fullscore/models/grid.h>




Action::AppendColumnToGrid::AppendColumnToGrid(Grid *grid)
   : Base("append_column_to_grid")
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




