#pragma once



class BeatCoordinate
{
public:
   int beat;
   int sub_beat_numerator;
   int sub_beat_denominator;

   BeatCoordinate(int beat=0, int sub_beat_numerator=0, int sub_beat_denominator=0);
   float get_x_offset();
};



