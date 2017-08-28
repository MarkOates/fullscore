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
   chord_quality_t quality;
   int inversion;
   std::vector<int> extensions;

   HarmonicAnalysisSymbol();
   ~HarmonicAnalysisSymbol();

   static std::string get_chord_quality_string(chord_quality_t chord_quality);
};



