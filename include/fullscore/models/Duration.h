#pragma once



#include <sstream>



class Duration
{
public:
   enum denominator_t
   {
      WHOLE = 1,
      HALF = 2,
      QUARTER = 4,
      EIGHTH = 8,
      SIXTEENTH = 16,
      THIRTYSECOND = 32,
      SIXTYFOURTH = 64,
   };

   denominator_t denominator;
   int dots;

   Duration(denominator_t denominator=QUARTER, int dots=0);
   bool operator==(const Duration &other) const;
   bool operator!=(const Duration &other) const;
};


std::istream& operator>> (std::istream& i, Duration::denominator_t &denominator);
Duration::denominator_t half_duration(Duration::denominator_t denominator);
Duration::denominator_t double_duration(Duration::denominator_t denominator);



