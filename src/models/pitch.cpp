


#include <fullscore/models/Pitch.h>



Pitch::Pitch(int scale_degree, int accidental)
   : scale_degree(scale_degree)
   , accidental(accidental)
{}



Pitch::~Pitch()
{
}



bool Pitch::set_scale_degree(int scale_degree)
{
   this->scale_degree = scale_degree;
   return true;
}



bool Pitch::set_accidental(int accidental)
{
   this->accidental = accidental;
   return true;
}



int Pitch::get_scale_degree() const
{
   return scale_degree;
}



int Pitch::get_accidental() const
{
   return accidental;
}



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



