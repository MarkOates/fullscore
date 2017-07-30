#ifndef __FULLSCORE_TIME_SIGNATURE_HEADER
#define __FULLSCORE_TIME_SIGNATURE_HEADER



#include <fullscore/models/duration.h>



class TimeSignature
{
private:
   int numerator;
   Duration denominator;

public:
   static const int NUMERATOR_MAX = 12;

   TimeSignature(int numerator, Duration denominator);
   ~TimeSignature();

   int get_numerator() const;
   Duration get_denominator() const;

   bool set_numerator(int numerator);
   bool set_denominator(Duration denominator);

   bool operator==(const TimeSignature &other) const;
   bool operator!=(const TimeSignature &other) const;
};




#endif
