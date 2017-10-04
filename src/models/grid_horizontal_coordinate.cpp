


#include <fullscore/models/grid_horizontal_coordinate.h>



GridHorizontalCoordinate::GridHorizontalCoordinate(int measure_num, int beat_num)
   : measure_num(measure_num)
   , beat_num(beat_num)
{}



void GridHorizontalCoordinate::set_measure_num(int measure_num)
{
   this->measure_num = measure_num;
}



void GridHorizontalCoordinate::set_beat_num(int beat_num)
{
   this->beat_num = beat_num;
}



int GridHorizontalCoordinate::get_measure_num()
{
   return measure_num;
}



int GridHorizontalCoordinate::get_beat_num()
{
   return beat_num;
}



