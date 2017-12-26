


#include <fullscore/converters/stream_operators/PitchStreamOperators.h>



std::ostream & operator<< (std::ostream &out, Pitch const &t)
{
   out << t.get_scale_degree() << " " << t.get_accidental();
   return out;
}



std::istream & operator>> (std::istream &in, Pitch &t)
{
   int scale_degree = 0;
   int accidental = 0;

   in >> scale_degree >> accidental;

   t.set_scale_degree(scale_degree);
   t.set_accidental(accidental);

   return in;
}



