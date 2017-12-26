



#include <fullscore/converters/stream_operators/DurationStreamOperators.h>
#include <fullscore/converters/TimeSignatureStringConverter.h>

#include <sstream>




TimeSignatureStringConverter::TimeSignatureStringConverter(TimeSignature *time_signature)
   : time_signature(time_signature)
{}




bool TimeSignatureStringConverter::read(std::string str)
{
   if (!time_signature) return false;

   std::stringstream ss;
   int numerator = 0;
   Duration denominator;

   ss << str;
   ss >> numerator >> denominator;

   time_signature->set_numerator(numerator);
   time_signature->set_denominator(denominator);

   return true;
}




std::string TimeSignatureStringConverter::write()
{
   if (!time_signature) return "";

   std::stringstream ss;
   ss << time_signature->get_numerator() << " " << time_signature->get_denominator();

   return ss.str();
}




