


#include <fullscore/models/Duration.h>

#include <allegro_flare/enum_iterator.h>
#include <allegro_flare/useful.h>
#include <vector>



Duration::Duration(denominator_t denominator, int dots)
   : denominator(denominator)
   , dots(dots)
{}



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



Duration::denominator_t half_duration(Duration::denominator_t denominator)
{
   if (denominator >= Duration::SIXTYFOURTH) return Duration::SIXTYFOURTH;
   return (Duration::denominator_t)((int)denominator * 2);
}



Duration::denominator_t double_duration(Duration::denominator_t denominator)
{
   if (denominator <= Duration::WHOLE) return Duration::WHOLE;
   return (Duration::denominator_t)((int)denominator / 2);
}



