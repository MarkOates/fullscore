


#include <fullscore/converters/stream_operators/DurationStreamOperators.h>



std::ostream & operator<< (std::ostream &out, Duration const &t)
{
   out << t.denominator << " " << t.dots;
   return out;
}



std::istream & operator>> (std::istream &in, Duration &t)
{
   int intermediary_denominator = 0;
   in >> intermediary_denominator >> t.dots;

   if (!Duration::is_valid_denominator(intermediary_denominator))
   {
      std::stringstream error_message;
      error_message << intermediary_denominator << " is not a valid Duration denominator_t" << std::endl;
      throw std::runtime_error(error_message.str());
   }

   t.denominator = (Duration::denominator_t)intermediary_denominator;

   return in;
}



