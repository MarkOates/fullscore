#pragma once



#include <fullscore/models/pitch.h>



class PitchRange
{
public:
   Pitch min, max;

   PitchRange(Pitch min, Pitch max);
   ~PitchRange();

   bool within(Pitch pitch);
   bool outside(Pitch pitch);
};



