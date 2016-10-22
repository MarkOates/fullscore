



#include <fullscore/converters/note_string_converter.h>

#include <sstream>




NoteStringConverter::NoteStringConverter(Note *note)
   : note(note)
{}




bool NoteStringConverter::read(std::string str)
{
   if (!note) return false;

   std::stringstream ss;
   ss << str;
   ss >> note->scale_degree >> note->accidental >> note->duration >> note->dots >> note->is_rest;

   return true;
}




std::string NoteStringConverter::write()
{
   if (!note) return "";

   std::stringstream ss;
   ss << note->scale_degree << " " << note->accidental << " " << note->duration << " " << note->dots << " " << note->is_rest;

   return ss.str();
}




