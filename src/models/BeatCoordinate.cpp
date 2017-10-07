


#include <fullscore/models/BeatCoordinate.h>



BeatCoordinate::BeatCoordinate(int beat, int sub_beat_numerator, int sub_beat_denominator)
   : beat(beat)
   , sub_beat_numerator(sub_beat_numerator)
   , sub_beat_denominator(sub_beat_denominator)
{}



float BeatCoordinate::get_x_offset()
{
   return beat + (float)sub_beat_numerator / sub_beat_denominator;
}




