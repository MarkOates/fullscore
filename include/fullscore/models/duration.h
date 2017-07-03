#pragma once



class Duration
{
public:
   int denominator;
   int dots;

   Duration(int denominator=4, int dots=0);
   bool operator==(const Duration &other) const;
};



