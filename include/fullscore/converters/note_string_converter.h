#ifndef __FULLSCORE_NOTE_STRING_CONVERTER_HEADER
#define __FULLSCORE_NOTE_STRING_CONVERTER_HEADER




#include <string>
#include <fullscore/models/note.h>




class NoteStringConverter
{
private:
   Note *note;

public:
   NoteStringConverter(Note *note);

   bool read(std::string);
   std::string write();
};




#endif
