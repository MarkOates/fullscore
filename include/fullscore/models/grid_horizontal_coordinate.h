#pragma once



#include <fullscore/models/BeatCoordinate.h>



class GridHorizontalCoordinate
{
private:
   int barline_num;
   BeatCoordinate beat_coordinate;

public:
   GridHorizontalCoordinate(int barline_num=0, BeatCoordinate beat_coordinate={});

   void set_barline_num(int barline_num);
   void set_beat_coordinate(BeatCoordinate beat_coordinate);
   int get_barline_num();
   BeatCoordinate get_beat_coordinate();

   bool operator==(const GridHorizontalCoordinate &other) const;
   bool operator!=(const GridHorizontalCoordinate &other) const;
};



