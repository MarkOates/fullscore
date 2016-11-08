



#include <fullscore/converters/time_signature_string_converter.h>

#include <sstream>




TimeSignatureStringConverter::TimeSignatureStringConverter(TimeSignature time_signature)
   : time_signature(time_signature)
{}




bool TimeSignatureStringConverter::read(std::string str)
{
   std::stringstream ss;
   ss << str;
   ss >> time_signature.numerator >> time_signature.denominator_duration >> time_signature.denominator_dots;

   return true;
}




std::string TimeSignatureStringConverter::write()
{
   std::stringstream ss;
   ss << time_signature.numerator << " " << time_signature.denominator_duration << " " << time_signature.denominator_dots;

   return ss.str();
}




