


#include <fullscore/models/pitch.h>



Pitch::Pitch(int scale_degree, int accidental)
   : scale_degree(scale_degree)
   , accidental(accidental)
{}



bool Pitch::operator==(const Pitch &other) const
{
   //TODO fix
   return (other.scale_degree == scale_degree);
}



