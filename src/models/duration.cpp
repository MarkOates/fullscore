


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



std::istream& operator>> (std::istream &i, Duration::denominator_t &denominator)
{
   denominator = Duration::QUARTER;
   std::string value;

   if (i >> value)
   {
      for (Duration::denominator_t d : EnumIterator<Duration::denominator_t, Duration::WHOLE, Duration::SIXTYFOURTH>())
      {
         if (value == tostring(d))
         {
            denominator = d;
            break;
         }
      }
   }
   return i;
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



