



#include <fullscore/converters/stream_operators/DurationStreamOperators.h>
#include <fullscore/converters/stream_operators/PitchStreamOperators.h>
#include <fullscore/converters/NoteStringConverter.h>

#include <sstream>




NoteStringConverter::NoteStringConverter(Note *note)
   : note(note)
{}




bool NoteStringConverter::read(std::string str)
{
   if (!note) return false;

   int scale_degree = 0;
   int accidental = 0;

   std::stringstream ss;
   ss << str;
   ss >> scale_degree >> accidental >> note->duration >> note->is_rest;

   note->pitch.set_scale_degree(scale_degree);
   note->pitch.set_accidental(accidental);

   return true;
}




std::string NoteStringConverter::write()
{
   if (!note) return "";

   std::stringstream ss;
   ss << note->pitch << " " << note->duration << " " << note->is_rest;

   return ss.str();
}




