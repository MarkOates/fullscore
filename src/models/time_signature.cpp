



#include <fullscore/models/time_signature.h>

#include <fullscore/constants.h>




TimeSignature::TimeSignature(int numerator, int denominator_duration, int denominator_dots)
   : numerator(numerator)
   , denominator_duration(denominator_duration)
   , denominator_dots(denominator_dots)
{
}




TimeSignature::~TimeSignature()
{
}




bool TimeSignature::_is_valid_duration(int duration)
{
   switch(duration)
   {
   case DURATION_WHOLE:
   case DURATION_HALF:
   case DURATION_QUARTER:
   case DURATION_EIGHTH:
   case DURATION_SIXTEENTH:
   case DURATION_THIRTYSECOND:
   case DURATION_SIXTYFOURTH:
      return true;
   }

   return false;
}




bool TimeSignature::set_numerator(int numerator)
{
   if (numerator <= 0) return false;
   if (numerator > 12) return false;

   this->numerator = numerator;
   return true;
}




bool TimeSignature::set_denominator(int denominator_duration, int denominator_dots)
{
   if (!_is_valid_duration(denominator_duration)) return false;
   if (denominator_dots < 0) return false;
   if (denominator_dots > 2) return false;

   this->denominator_duration = denominator_duration;
   this->denominator_dots = denominator_dots;
   return true;
}




