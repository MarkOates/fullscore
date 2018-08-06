


#include <fullscore/converters/stream_operators/NoteStreamOperators.h>

#include <fullscore/converters/stream_operators/DurationStreamOperators.h>
#include <fullscore/converters/stream_operators/PitchStreamOperators.h>
#include <fullscore/models/Duration.h>
#include <fullscore/models/Pitch.h>



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



