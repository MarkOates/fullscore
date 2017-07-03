#ifndef __FULLSCORE_TIME_SIGNATURE_HEADER
#define __FULLSCORE_TIME_SIGNATURE_HEADER



#include <fullscore/models/duration.h>



class TimeSignature
{
private:
   friend class TimeSignatureRenderComponent;
   friend class TimeSignatureStringConverter;
   friend class DurationHelper;

   int numerator;
   Duration denominator;

   bool _is_valid_duration(int duration);

public:
   TimeSignature(int numerator, Duration denominator);
   ~TimeSignature();

   bool set_numerator(int numerator);
   bool set_denominator(Duration denominator);
   float get_width();

   bool operator==(TimeSignature &other);
   bool operator!=(TimeSignature &other);
};




#endif
