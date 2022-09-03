#pragma once



#include <fullscore/models/Duration.hpp>



class TempoMarking
{
public:
   Duration duration;
   int bpm;

   TempoMarking(Duration duration, int bpm);
   ~TempoMarking();
};



