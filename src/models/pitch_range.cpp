


#include <fullscore/models/pitch_range.h>



PitchRange::PitchRange(Pitch min, Pitch max)
   : min(min)
   , max(max)
{
}



PitchRange::~PitchRange()
{
}



bool PitchRange::within(Pitch pitch)
{
   return !outside(pitch);
}



bool PitchRange::outside(Pitch pitch)
{
   return (pitch < min) || (pitch > max);
}



