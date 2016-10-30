



#include <fullscore/actions/append_measure_action.h>

#include <fullscore/models/measure_grid.h>




Action::AppendMeasure::AppendMeasure(MeasureGrid *measure_grid)
   : Base("append_measure")
   , measure_grid(measure_grid)
{}




Action::AppendMeasure::~AppendMeasure()
{}




bool Action::AppendMeasure::execute()
{
   if (!measure_grid) return false;

   // unimplemented
   return false;
}




