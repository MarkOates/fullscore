


#include <fullscore/models/harmonic_analysis_symbol.h>



HarmonicAnalysisSymbol::HarmonicAnalysisSymbol()
   : fundamental(0, 0)
   , quality(MAJOR)
   , inversion(0)
   , extensions()
{}



HarmonicAnalysisSymbol::~HarmonicAnalysisSymbol()
{}



std::string HarmonicAnalysisSymbol::get_chord_quality_string(chord_quality_t chord_quality)
{
   switch(chord_quality)
   {
      case HarmonicAnalysisSymbol::MAJOR: return "major";
      case HarmonicAnalysisSymbol::MINOR: return "minor";
      case HarmonicAnalysisSymbol::AUGMENTED: return "augmented";
      case HarmonicAnalysisSymbol::DIMINISHED: return "diminished";
   }

   return "[undef]";
}



