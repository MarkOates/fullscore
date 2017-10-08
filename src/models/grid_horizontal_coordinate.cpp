


#include <fullscore/models/grid_horizontal_coordinate.h>



GridHorizontalCoordinate::GridHorizontalCoordinate(int measure_num, BeatCoordinate beat_coordinate)
   : measure_num(measure_num)
   , beat_coordinate(beat_coordinate)
{}



void GridHorizontalCoordinate::set_measure_num(int measure_num)
{
   this->measure_num = measure_num;
}



void GridHorizontalCoordinate::set_beat_coordinate(BeatCoordinate beat_coordinate)
{
   this->beat_coordinate = beat_coordinate;
}



int GridHorizontalCoordinate::get_measure_num()
{
   return measure_num;
}



BeatCoordinate GridHorizontalCoordinate::get_beat_coordinate()
{
   return beat_coordinate;
}



