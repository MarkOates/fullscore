


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



