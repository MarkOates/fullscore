



#include <fullscore/converters/note_string_converter.h>

#include <sstream>




NoteStringConverter::NoteStringConverter(Note *note)
   : note(note)
{}




bool NoteStringConverter::read(std::string str)
{
   if (!note) return false;

   if (format_version == 0)
   {
      std::stringstream ss;
      ss << str;
      ss >> scale_degree >> accidental >> duration >> dots >> is_rest;
      return true;
   }
   return false;
}




std::string NoteStringConverter::write()
{
   if (!note) return "";

   std::stringstream ss;
   if (format_version == 0)
   {
      ss << scale_degree << " " << accidental << " " << duration << " " << dots << " " << is_rest;
   }
   return ss.str();
}




