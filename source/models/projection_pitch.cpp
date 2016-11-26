


#include <fullscore/models/projection_pitch.h>



ProjectionPitch::ProjectionPitch(int pitch)
   : pitch(pitch)
{}



bool ProjectionPitch::operator==(const ProjectionPitch &other) const
{
   return (other.pitch == pitch);
}



