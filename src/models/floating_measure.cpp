


#include <fullscore/models/floating_measure.h>



FloatingMeasure::FloatingMeasure(GridCoordinate coordinate, int measure_id)
   : id(FloatingMeasure::next_id++)
   , coordinate(coordinate)
   , measure_id(measure_id)
{
}



FloatingMeasure::~FloatingMeasure()
{
}



GridCoordinate FloatingMeasure::get_coordinate()
{
   return coordinate;
}



int FloatingMeasure::get_measure_id()
{
   return measure_id;
}



int FloatingMeasure::get_id()
{
   return id;
}



int FloatingMeasure::next_id = 0;



int FloatingMeasure::get_next_id()
{
   return next_id;
}



