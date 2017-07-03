#pragma once



class Pitch
{
public:
   int pitch;
   int accidental;

   Pitch(int pitch, int accidental=0);

   bool operator==(const Pitch &other) const;
};



