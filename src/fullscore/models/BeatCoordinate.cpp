


#include <fullscore/models/BeatCoordinate.hpp>



BeatCoordinate::BeatCoordinate(int beat, int sub_beat_numerator, int sub_beat_denominator)
   : beat(beat)
   , sub_beat_numerator(sub_beat_numerator)
   , sub_beat_denominator(sub_beat_denominator)
{}



float BeatCoordinate::get_x_offset()
{
   if (sub_beat_denominator == 0) return (float)beat;
   return beat + (float)sub_beat_numerator / sub_beat_denominator;
}



bool BeatCoordinate::operator==(const BeatCoordinate &other) const
{
   return (
      this->beat == other.beat
      && this->sub_beat_numerator == other.sub_beat_numerator
      && this->sub_beat_denominator == other.sub_beat_denominator
   );
}



bool BeatCoordinate::operator!=(const BeatCoordinate &other) const
{
   return !(*this == other);
}



