


#include <fullscore/converters/stream_operators/BeatCoordinateStreamOperators.h>




std::ostream & operator<< (std::ostream &out, BeatCoordinate const &t)
{
   out << t.beat << " " << t.sub_beat_numerator << " " << t.sub_beat_denominator;
   return out;
}



std::istream & operator>> (std::istream &in, BeatCoordinate &t)
{
   in >> t.beat >> t.sub_beat_numerator >> t.sub_beat_denominator;
   return in;
}



