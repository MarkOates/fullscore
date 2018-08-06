


#include <fullscore/models/FloatingMeasureCursor.h>



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



void FloatingMeasureCursor::clear_floating_measure_id()
{
   this->floating_measure_id = -1;
}



int FloatingMeasureCursor::get_floating_measure_id()
{
   return floating_measure_id;
}



