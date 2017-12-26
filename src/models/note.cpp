


#include <fullscore/models/Note.h>



Note::Note(int _scale_degree, Duration duration)
   : pitch(Pitch(_scale_degree, 0))
   , duration(duration)
   , is_rest(false)
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
   this->is_rest = rest;
   return true;
}



Pitch Note::get_pitch()
{
   return pitch;
}



Duration Note::get_duration()
{
   return duration;
}



bool Note::get_rest()
{
   return is_rest;
}



bool Note::operator==(const Note &other) const
{
   return (pitch == other.pitch
         && duration == other.duration
         && is_rest == other.is_rest);
}



