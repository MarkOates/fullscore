#pragma once



class TimeSignature;

class DurationHelper
{
public:
   static float get_length(int duration, int dots);
   static float get_length(const TimeSignature &time_signature);
};



