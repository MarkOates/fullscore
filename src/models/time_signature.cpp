



#include <fullscore/models/time_signature.h>

#include <fullscore/models/duration.h>
#include <fullscore/helpers/duration_helper.h>




TimeSignature::TimeSignature(int numerator, Duration denominator)
   : numerator(numerator)
   , denominator(denominator)
{
}




TimeSignature::~TimeSignature()
{
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




bool TimeSignature::operator==(TimeSignature &other)
{
   return (numerator == other.numerator) && (denominator == other.denominator);
}




bool TimeSignature::operator!=(TimeSignature &other)
{
   return !(*this == other);
}




