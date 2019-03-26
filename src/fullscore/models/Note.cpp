


#include <fullscore/models/Note.h>



Note::Note(int _scale_degree, Duration duration, bool rest)
   : pitch(Pitch(_scale_degree, 0))
   , duration(duration)
   , rest(rest)
{}



Note::~Note()
{}



bool Note::set_pitch(Pitch pitch)
{
   this->pitch = pitch;
   return true;
}



bool Note::set_duration(Duration duration)
{
   this->duration = duration;
   return true;
}



bool Note::set_rest(bool rest)
{
   this->rest = rest;
   return true;
}



Pitch Note::get_pitch() const
{
   return pitch;
}



Duration Note::get_duration() const
{
   return duration;
}



bool Note::get_rest() const
{
   return rest;
}



bool Note::operator==(const Note &other) const
{
   return (pitch == other.pitch
         && duration == other.duration
         && rest == other.rest);
}



