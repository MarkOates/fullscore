



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




float TimeSignature::get_width()
{
   float width = 1.0f / denominator_duration;
   float dots_percentage = 0.0f;
   float previous_ammount = 1.0f;
   for (int i=0; i<denominator_dots; i++)
   {
      previous_ammount *= 0.5f;
      dots_percentage += previous_ammount;
   }

   return width + width * dots_percentage;
}




bool TimeSignature::operator==(TimeSignature &other)
{
   return (numerator == other.numerator)
      && (denominator_duration == other.denominator_duration)
      && (denominator_dots == other.denominator_dots);
}




bool TimeSignature::operator!=(TimeSignature &other)
{
   return !(*this == other);
}




