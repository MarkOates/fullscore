


#include <fullscore/models/duration.h>



Duration::Duration(int denominator, int dots)
   : denominator(denominator)
   , dots(dots)
{}



bool Duration::operator==(const Duration &other) const
{
   return (denominator == other.denominator
         && dots == other.dots);
}



