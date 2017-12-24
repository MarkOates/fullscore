


#include <fullscore/models/Duration.h>

#include <allegro_flare/enum_iterator.h>
#include <allegro_flare/useful.h>



Duration::Duration(denominator_t denominator, int dots)
   : denominator(denominator)
   , dots(dots)
{}



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



