#pragma once



class Pitch
{
public:
   int scale_degree;
   int accidental;

   Pitch(int scale_degree, int accidental=0);
   ~Pitch();

   bool operator==(const Pitch &other) const;
   bool operator>(const Pitch &other) const;
   bool operator<(const Pitch &other) const;
};



