



#include <fullscore/actions/SNAKECASE_ACTION_NAME_action.h>

#include <fullscore/models/measure_grid.h>




Action::CLASS_NAME::CLASS_NAME(MeasureGrid *measure_grid)
   : Base("SNAKECASE_ACTION_NAME")
   , measure_grid(measure_grid)
{}




Action::CLASS_NAME::~CLASS_NAME()
{}




bool Action::CLASS_NAME::execute()
{
   if (!measure_grid) return false;

   // unimplemented
   return false;
}




