


#include <fullscore/models/projection_pitch.h>



ProjectionPitch::ProjectionPitch(int pitch, int accidental)
   : pitch(pitch)
   , accidental(accidental)
{}



bool ProjectionPitch::operator==(const ProjectionPitch &other) const
{
   return (other.pitch == pitch);
}



