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

private:
   denominator_t denominator;
   int dots;

public:
   Duration(denominator_t denominator=QUARTER, int dots=0);

   void set_denominator(denominator_t denominator);
   void set_dots(int dots);

   denominator_t get_denominator() const;
   int get_dots() const;

   static bool is_valid_denominator(int value);

   bool operator==(const Duration &other) const;
   bool operator!=(const Duration &other) const;
};



