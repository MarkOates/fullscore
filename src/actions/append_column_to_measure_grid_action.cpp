



#include <fullscore/actions/append_column_to_measure_grid_action.h>

#include <fullscore/models/measure_grid.h>




Action::AppendMeasure::AppendMeasure(MeasureGrid *measure_grid)
   : Base("append_column_to_measure_grid")
   , measure_grid(measure_grid)
{}




Action::AppendMeasure::~AppendMeasure()
{}




bool Action::AppendMeasure::execute()
{
   if (!measure_grid) return false;

   measure_grid->append_measure();

   return false;
}




