


#include <fullscore/models/pitch.h>



Pitch::Pitch(int scale_degree, int accidental)
   : scale_degree(scale_degree)
   , accidental(accidental)
{}



bool Pitch::operator==(const Pitch &other) const
{
   return (scale_degree == other.scale_degree && accidental == other.accidental);
}



bool Pitch::operator>(const Pitch &other) const
{
   return (scale_degree+accidental > other.scale_degree+other.accidental);
}



bool Pitch::operator<(const Pitch &other) const
{
   return (scale_degree+accidental < other.scale_degree+other.accidental);
}



