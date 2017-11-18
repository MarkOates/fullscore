#pragma once



class ScientificPitchNotationToPitchConverter
{
private:
   char note_name;
   int octave;
   int accidental;

public:
   ScientificPitchNotationToPitchConverter(char note_name, int octave, int accidental=0);
   ~ScientificPitchNotationToPitchConverter();

   int convert();
};



using SPNToPitchConverter = ScientificPitchNotationToPitchConverter;



