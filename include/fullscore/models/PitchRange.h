#pragma once



#include <fullscore/models/Pitch.h>



class PitchRange
{
public:
   Pitch min, max;

   PitchRange(Pitch min, Pitch max);
   ~PitchRange();

   bool within(Pitch pitch);
   bool outside(Pitch pitch);
};



