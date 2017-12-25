


#include <fullscore/converters/stream_operators/DurationStreamOperators.h>



std::ostream & operator<< (std::ostream &out, Duration const &t)
{
   out << t.denominator << " " << t.dots;
   return out;
}



std::istream & operator>> (std::istream &in, Duration &t)
{
   int denominator = 0;
   int dots = 0;

   in >> denominator >> dots;

   t.set_denominator(denominator);
   t.set_dots(dots);

   return in;
}



