


#include <fullscore/models/time_signature.h>

#include <fullscore/models/Duration.h>
#include <fullscore/helpers/duration_helper.h>



TimeSignature::TimeSignature(int numerator, Duration denominator)
   : numerator(numerator)
   , denominator(denominator)
{
}



TimeSignature::~TimeSignature()
{
}



int TimeSignature::get_numerator() const
{
   return numerator;
}



Duration TimeSignature::get_denominator() const
{
   return denominator;
}



bool TimeSignature::set_numerator(int numerator)
{
   if (numerator <= 0) return false;
   if (numerator > NUMERATOR_MAX) return false;

   this->numerator = numerator;
   return true;
}



bool TimeSignature::set_denominator(Duration denominator)
{
   this->denominator = denominator;
   return true;
}



bool TimeSignature::operator==(const TimeSignature &other) const
{
   return (numerator == other.numerator) && (denominator == other.denominator);
}



bool TimeSignature::operator!=(const TimeSignature &other) const
{
   return !(*this == other);
}



