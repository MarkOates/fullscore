


#include <fullscore/models/harmonic_analysis_symbol.h>



HarmonicAnalysisSymbol::HarmonicAnalysisSymbol(Pitch fundamental, chord_quality_t chord_quality, int inversion, std::vector<int> extensions)
   : fundamental(fundamental)
   , chord_quality(chord_quality)
   , inversion(inversion)
   , extensions(extensions)
{}



HarmonicAnalysisSymbol::~HarmonicAnalysisSymbol()
{}



std::string HarmonicAnalysisSymbol::get_chord_quality_string(chord_quality_t chord_quality, bool abbreviated)
{
   switch(chord_quality)
   {
      case HarmonicAnalysisSymbol::MAJOR: return abbreviated ? "maj" : "major";
      case HarmonicAnalysisSymbol::MINOR: return abbreviated ? "min" : "minor";
      case HarmonicAnalysisSymbol::AUGMENTED: return abbreviated ? "aug" : "augmented";
      case HarmonicAnalysisSymbol::DIMINISHED: return abbreviated ? "dim" : "diminished";
   }

   return "[undef]";
}



std::string HarmonicAnalysisSymbol::get_roman_numeral_string(int number, chord_quality_t chord_quality)
{
   bool quality_is_major = (chord_quality == MAJOR || chord_quality == AUGMENTED);

   switch(number)
   {
   case 0: return quality_is_major ? "O" : "o"; break;
   case 1: return quality_is_major ? "I" : "i"; break;
   case 2: return quality_is_major ? "II" : "ii"; break;
   case 3: return quality_is_major ? "III" : "iii"; break;
   case 4: return quality_is_major ? "IV" : "iv"; break;
   case 5: return quality_is_major ? "V" : "v"; break;
   case 6: return quality_is_major ? "VI" : "vi"; break;
   case 7: return quality_is_major ? "VII" : "vii"; break;
   case 8: return quality_is_major ? "IIX" : "iix"; break;
   case 9: return quality_is_major ? "IX" : "ix"; break;
   case 10: return quality_is_major ? "X" : "x"; break;
   case 11: return quality_is_major ? "XI" : "xi"; break;
   default: return "--"; break;
   }
}



