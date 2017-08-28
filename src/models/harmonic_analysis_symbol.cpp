


#include <fullscore/models/harmonic_analysis_symbol.h>



HarmonicAnalysisSymbol::HarmonicAnalysisSymbol()
   : fundamental(0, 0)
   , chord_quality(MAJOR)
   , inversion(0)
   , extensions()
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



