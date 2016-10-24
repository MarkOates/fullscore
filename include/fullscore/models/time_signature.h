#ifndef __FULLSCORE_TIME_SIGNATURE_HEADER
#define __FULLSCORE_TIME_SIGNATURE_HEADER




class TimeSignature
{
private:
   int numerator;
   int denominator_duration;
   int denominator_dots;

   bool _is_valid_duration(int duration);

public:
   TimeSignature(int numerator, int denominator_duration, int denominator_dots=0);
   ~TimeSignature();

   bool set_numerator(int numerator);
   bool set_denominator(int denominator_duration, int denominator_dots=0);
};




#endif
