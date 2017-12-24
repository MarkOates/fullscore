#pragma once



#include <fullscore/models/Note.h>
#include <string>



class NoteStringConverter
{
private:
   Note *note;

public:
   NoteStringConverter(Note *note);

   bool read(std::string);
   std::string write();
};



