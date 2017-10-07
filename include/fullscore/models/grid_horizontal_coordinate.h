#pragma once



#include <fullscore/models/BeatCoordinate.h>



class GridHorizontalCoordinate
{
private:
   int measure_num;
   BeatCoordinate beat_coordinate;

public:
   GridHorizontalCoordinate(int measure_num=0, BeatCoordinate beat_coordinate={});

   void set_measure_num(int measure_num);
   void set_beat_coordinate(BeatCoordinate beat_coordinate);
   int get_measure_num();
   BeatCoordinate get_beat_coordinate();
};



