


#include <fullscore/converters/stream_operators/DurationStreamOperators.hpp>
#include <fullscore/converters/stream_operators/TimeSignatureStreamOperators.hpp>



std::ostream & operator<< (std::ostream &out, TimeSignature const &t)
{
   out << t.get_numerator() << " " << t.get_denominator();
   return out;
}



std::istream & operator>> (std::istream &in, TimeSignature &t)
{
   int numerator;
   Duration denominator;

   in >> numerator >> denominator;

   t.set_numerator(numerator);
   t.set_denominator(denominator);

   return in;
}



