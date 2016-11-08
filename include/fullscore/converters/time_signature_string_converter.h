#pragma once




#include <string>
#include <fullscore/models/time_signature.h>




class TimeSignatureStringConverter
{
private:
   TimeSignature time_signature;

public:
   TimeSignatureStringConverter(TimeSignature time_signature);

   bool read(std::string);
   std::string write();
};




