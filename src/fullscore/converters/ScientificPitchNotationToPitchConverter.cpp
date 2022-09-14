


#include <fullscore/converters/ScientificPitchNotationToPitchConverter.hpp>

#include <sstream>



ScientificPitchNotationToPitchConverter::ScientificPitchNotationToPitchConverter(char note_name, int octave, int accidental)
   : note_name(note_name)
   , octave(octave)
   , accidental(accidental)
{
}



ScientificPitchNotationToPitchConverter::~ScientificPitchNotationToPitchConverter()
{
}



int ScientificPitchNotationToPitchConverter::convert()
{
   int result_pitch = 0;

   switch (note_name)
   {
   case 'C': result_pitch = 0; break;
   case 'D': result_pitch = 2; break;
   case 'E': result_pitch = 4; break;
   case 'F': result_pitch = 5; break;
   case 'G': result_pitch = 7; break;
   case 'A': result_pitch = 9; break;
   case 'B': result_pitch = 11; break;
   default:
      {
         std::stringstream error_message;
         error_message
            << "Cannot convert from scientific pitch notation to pitch with an invalid note_name \""
            << note_name
            << "\"";
         throw std::runtime_error(error_message.str());
      }
      break;
   };

   return result_pitch + (octave - 4) * 12 + accidental;
}



