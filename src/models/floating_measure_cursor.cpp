


#include <fullscore/models/floating_measure_cursor.h>



FloatingMeasureCursor::FloatingMeasureCursor()
   : floating_measure_id(-1)
{
}



FloatingMeasureCursor::~FloatingMeasureCursor()
{
}



bool FloatingMeasureCursor::set_floating_measure_id(int floating_measure_id)
{
   this->floating_measure_id = floating_measure_id;
   return true;
}



int FloatingMeasureCursor::get_floating_measure_id()
{
   return floating_measure_id;
}



