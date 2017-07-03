



#include <fullscore/models/time_signature.h>

#include <fullscore/models/duration.h>




TimeSignature::TimeSignature(int numerator, Duration denominator)
   : numerator(numerator)
   , denominator(denominator)
{
}




TimeSignature::~TimeSignature()
{
}




bool TimeSignature::_is_valid_duration(int duration)
{
   switch(duration)
   {
   case Duration::WHOLE:
   case Duration::HALF:
   case Duration::QUARTER:
   case Duration::EIGHTH:
   case Duration::SIXTEENTH:
   case Duration::THIRTYSECOND:
   case Duration::SIXTYFOURTH:
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




bool TimeSignature::set_denominator(Duration denominator)
{
   this->denominator = denominator;
   return true;
}




float TimeSignature::get_width()
{
   float width = 1.0f / denominator.denominator;
   float dots_percentage = 0.0f;
   float previous_ammount = 1.0f;
   for (int i=0; i<denominator.dots; i++)
   {
      previous_ammount *= 0.5f;
      dots_percentage += previous_ammount;
   }

   return width + width * dots_percentage;
}




bool TimeSignature::operator==(TimeSignature &other)
{
   return (numerator == other.numerator)
      && (denominator.denominator == other.denominator.denominator)
      && (denominator.dots == other.denominator.dots);
}




bool TimeSignature::operator!=(TimeSignature &other)
{
   return !(*this == other);
}




