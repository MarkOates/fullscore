



#include <fullscore/models/time_signature.h>




TimeSignature::TimeSignature(int numerator, int denominator_duration, int denominator_dots)
   : numerator(numerator)
   , denominator_duration(denominator_duration)
   , denominator_dots(denominator_dots)
{
}




TimeSignature::~TimeSignature()
{
}




bool TimeSignature::set_numerator(int numerator)
{
   this->numerator = numerator;
   return true;
}




bool TimeSignature::set_denominator(int denominator_duration, int denominator_dots)
{
   this->denominator_duration = denominator_duration;
   this->denominator_dots = denominator_dots;
   return true;
}




