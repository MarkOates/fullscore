#pragma once



#include <fullscore/models/Duration.h>



class TempoMarking
{
public:
   Duration duration;
   int bpm;

   TempoMarking(Duration duration, int bpm);
   ~TempoMarking();
};



