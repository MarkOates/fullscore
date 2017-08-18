#pragma once



#include <fullscore/models/time_signature.h>
#include <string>



class TimeSignatureStringConverter
{
private:
   TimeSignature *time_signature;

public:
   TimeSignatureStringConverter(TimeSignature *time_signature);

   bool read(std::string);
   std::string write();
};



