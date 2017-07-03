


#include <fullscore/models/pitch.h>



Pitch::Pitch(int pitch, int accidental)
   : pitch(pitch)
   , accidental(accidental)
{}



bool Pitch::operator==(const Pitch &other) const
{
   return (other.pitch == pitch);
}



