


#include <fullscore/converters/stream_operators/NoteStreamOperators.hpp>

#include <fullscore/converters/stream_operators/DurationStreamOperators.hpp>
#include <fullscore/converters/stream_operators/PitchStreamOperators.hpp>
#include <fullscore/models/Duration.hpp>
#include <fullscore/models/Pitch.hpp>



std::ostream & operator<< (std::ostream &out, Note const &t)
{
   out << t.get_pitch() << " " << t.get_duration() << " " << t.get_rest();
   return out;
}



std::istream & operator>> (std::istream &in, Note &t)
{
   Pitch pitch;
   Duration duration;
   bool rest;

   in >> pitch >> duration >> rest;

   t.set_pitch(pitch);
   t.set_duration(duration);
   t.set_rest(rest);

   return in;
}



