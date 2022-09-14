#pragma once



#include <fullscore/models/Duration.hpp>



class TimeSignature;

class DurationHelper
{
public:
   static float get_length(Duration duration);
   static float get_length(const TimeSignature &time_signature);
   static Duration::denominator_t half_duration(Duration::denominator_t denominator);
   static Duration::denominator_t double_duration(Duration::denominator_t denominator);
};



