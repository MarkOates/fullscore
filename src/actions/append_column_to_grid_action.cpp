



#include <fullscore/actions/append_column_to_grid_action.h>

#include <fullscore/models/grid.h>




Action::AppendColumnToMeasureGrid::AppendColumnToMeasureGrid(MeasureGrid *grid)
   : Base("append_column_to_grid")
   , grid(grid)
{}




Action::AppendColumnToMeasureGrid::~AppendColumnToMeasureGrid()
{}




bool Action::AppendColumnToMeasureGrid::execute()
{
   if (!grid) return false;

   grid->append_measure();

   return false;
}




