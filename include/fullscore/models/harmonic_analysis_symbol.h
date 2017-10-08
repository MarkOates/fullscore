#pragma once



#include <fullscore/models/pitch.h>
#include <string>
#include <vector>



class HarmonicAnalysisSymbol
{
public:
   enum chord_quality_t
   {
      MAJOR=1,
      MINOR=2,
      AUGMENTED=3,
      DIMINISHED=4,
   };

   Pitch fundamental;
   chord_quality_t chord_quality;
   int inversion;
   std::vector<int> extensions;

   HarmonicAnalysisSymbol(Pitch fundamental, chord_quality_t chord_quality, int inversion, std::vector<int> extensions);
   ~HarmonicAnalysisSymbol();

   static std::string get_chord_quality_string(chord_quality_t chord_quality, bool abbreviated=false);
   static std::string get_roman_numeral_string(int number, chord_quality_t chord_quality);
   static std::string get_accidental_string(int accidental);
};



