


#include <fullscore/models/projection_pitch.h>



ProjectionPitch::ProjectionPitch(int pitch, int extension, int accidental)
   : pitch(pitch)
   , extension(extension)
   , accidental(accidental)
{}



bool ProjectionPitch::operator==(const ProjectionPitch &other) const
{
   return (other.pitch == pitch
         && other.extension == extension
         && other.accidental == accidental);
}



