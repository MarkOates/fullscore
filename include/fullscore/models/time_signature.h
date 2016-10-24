#ifndef __FULLSCORE_TIME_SIGNATURE_HEADER
#define __FULLSCORE_TIME_SIGNATURE_HEADER




class TimeSignature
{
public:
   int numerator;
   int denominator_duration;
   int denominator_dots;

   TimeSignature(int numerator, int denominator_duration, int denominator_dots=0);
   ~TimeSignature();
};




#endif
