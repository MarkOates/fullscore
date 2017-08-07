



#include <fullscore/actions/append_column_to_measure_grid_action.h>

#include <fullscore/models/measure_grid.h>




Action::AppendColumnToMeasureGrid::AppendColumnToMeasureGrid(MeasureGrid *measure_grid)
   : Base("append_column_to_measure_grid")
   , measure_grid(measure_grid)
{}




Action::AppendColumnToMeasureGrid::~AppendColumnToMeasureGrid()
{}




bool Action::AppendColumnToMeasureGrid::execute()
{
   if (!measure_grid) return false;

   measure_grid->append_measure();

   return false;
}




