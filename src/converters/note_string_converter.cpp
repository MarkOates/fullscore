



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
   ss >> note->pitch.scale_degree >> note->pitch.accidental >> note->duration.denominator >> note->duration.dots >> note->is_rest;

   return true;
}




std::string NoteStringConverter::write()
{
   if (!note) return "";

   std::stringstream ss;
   ss << note->pitch.scale_degree << " " << note->pitch.accidental << " " << note->duration.denominator << " " << note->duration.dots << " " << note->is_rest;

   return ss.str();
}




