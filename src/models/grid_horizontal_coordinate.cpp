


#include <fullscore/models/grid_horizontal_coordinate.h>



GridHorizontalCoordinate::GridHorizontalCoordinate(int barline_num, BeatCoordinate beat_coordinate)
   : barline_num(barline_num)
   , beat_coordinate(beat_coordinate)
{}



void GridHorizontalCoordinate::set_barline_num(int barline_num)
{
   this->barline_num = barline_num;
}



void GridHorizontalCoordinate::set_beat_coordinate(BeatCoordinate beat_coordinate)
{
   this->beat_coordinate = beat_coordinate;
}



int GridHorizontalCoordinate::get_barline_num()
{
   return barline_num;
}



BeatCoordinate GridHorizontalCoordinate::get_beat_coordinate()
{
   return beat_coordinate;
}



bool GridHorizontalCoordinate::operator==(const GridHorizontalCoordinate &other) const
{
   return (this->barline_num == other.barline_num && this->beat_coordinate == other.beat_coordinate);
}



bool GridHorizontalCoordinate::operator!=(const GridHorizontalCoordinate &other) const
{
   return !(*this == other);
}



