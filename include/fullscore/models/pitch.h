#pragma once



class Pitch
{
private:
   int scale_degree;
   int accidental;

public:
   Pitch(int scale_degree, int accidental=0);
   ~Pitch();

   bool set_scale_degree(int scale_degree);
   bool set_accidental(int accidental);

   int get_scale_degree() const;
   int get_accidental() const;

   bool operator==(const Pitch &other) const;
   bool operator>(const Pitch &other) const;
   bool operator<(const Pitch &other) const;
};



