


#include <fullscore/models/duration.h>

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

      //if (value == tostring(Duration::WHOLE)) denominator = Duration::WHOLE;
      //else if (value == tostring(Duration::HALF))  denominator = Duration::HALF;
      //else if (value == tostring(Duration::QUARTER)) denominator = Duration::QUARTER;
      //else if (value == tostring(Duration::EIGHTH)) denominator = Duration::EIGHTH;
      //else if (value == tostring(Duration::SIXTEENTH)) denominator = Duration::SIXTEENTH;
      //else if (value == tostring(Duration::THIRTYSECOND)) denominator = Duration::THIRTYSECOND;
      //else if (value == tostring(Duration::SIXTYFOURTH)) denominator = Duration::SIXTYFOURTH;
   }
   return i;
}



Duration::denominator_t half_duration(Duration::denominator_t denominator)
{
   return (Duration::denominator_t)((int)denominator * 2);
}



Duration::denominator_t double_duration(Duration::denominator_t denominator)
{
   return (Duration::denominator_t)((int)denominator / 2);
}



