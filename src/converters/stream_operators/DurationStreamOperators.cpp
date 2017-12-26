


#include <fullscore/converters/stream_operators/DurationStreamOperators.h>



std::ostream & operator<< (std::ostream &out, Duration const &t)
{
   out << t.get_denominator() << " " << t.get_dots();
   return out;
}



std::istream & operator>> (std::istream &in, Duration &t)
{
   int denominator = 0;
   int dots = 0;

   in >> denominator >> dots;

   t.set_denominator((Duration::denominator_t)denominator);
   t.set_dots(dots);

   return in;
}



