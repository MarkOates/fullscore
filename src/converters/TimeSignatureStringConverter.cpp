



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
   Duration::denominator_t denominator_denominator = Duration::QUARTER;
   int denominator_dots = 0;

   ss << str;
   ss >> numerator >> denominator_denominator >> denominator_dots;

   time_signature->set_numerator(numerator);
   time_signature->set_denominator(Duration(denominator_denominator, denominator_dots));

   return true;
}




std::string TimeSignatureStringConverter::write()
{
   if (!time_signature) return "";

   std::stringstream ss;
   ss << time_signature->get_numerator() << " " << time_signature->get_denominator().denominator << " " << time_signature->get_denominator().dots;

   return ss.str();
}




