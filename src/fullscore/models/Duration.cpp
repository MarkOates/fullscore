


#include <fullscore/models/Duration.hpp>

//#include <AllegroFlare/Useful.hpp>
#include <vector>



Duration::Duration(denominator_t denominator, int dots)
   : denominator(denominator)
   , dots(dots)
{}



void Duration::set_denominator(denominator_t denominator)
{
   if (!Duration::is_valid_denominator(denominator))
   {
      std::stringstream error_message;
      error_message << "Cannot set_denominator. \"" << denominator << "\" is not a valid Duration denominator_t" << std::endl;
      throw std::invalid_argument(error_message.str());
   }

   this->denominator = denominator;
}




void Duration::set_dots(int dots)
{
   this->dots = dots;
}




Duration::denominator_t Duration::get_denominator() const
{
   return denominator;
}




int Duration::get_dots() const
{
   return dots;
}




bool Duration::is_valid_denominator(int value)
{
   std::vector<denominator_t> valid_denominators = {
      WHOLE,
      HALF,
      QUARTER,
      EIGHTH,
      SIXTEENTH,
      THIRTYSECOND,
      SIXTYFOURTH,
   };

   for (int i=0; i<valid_denominators.size(); i++)
      if (valid_denominators[i] == (Duration::denominator_t)value) return true;
   return false;
}



bool Duration::operator==(const Duration &other) const
{
   return (denominator == other.denominator
         && dots == other.dots);
}



bool Duration::operator!=(const Duration &other) const
{
   return !(*this == other);
}



