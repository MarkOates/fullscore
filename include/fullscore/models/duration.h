#pragma once



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

   int denominator;
   int dots;

   Duration(int denominator=4, int dots=0);
   bool operator==(const Duration &other) const;
};



