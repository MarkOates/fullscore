



#include <fullscore/actions/insert_measure_action.h>




Action::InsertMeasure::InsertMeasure(MeasureGrid *measure_grid, int at_index)
   : Base("insert_measure")
   , measure_grid(measure_grid)
   , at_index(at_index)
{}




Action::InsertMeasure::~InsertMeasure()
{}




bool Action::InsertMeasure::execute()
{
   // unimplemented
   return false;
}




