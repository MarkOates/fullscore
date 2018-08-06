


#include <fullscore/models/staves/HarmonicAnalysis.h>

#include <fullscore/models/measures/Base.h>



Staff::HarmonicAnalysis::HarmonicAnalysisSymbolPlacement::HarmonicAnalysisSymbolPlacement(GridHorizontalCoordinate coordinate, HarmonicAnalysisSymbol symbol)
   : coordinate(coordinate)
   , symbol(symbol)
{}



Staff::HarmonicAnalysis::HarmonicAnalysis()
   : Base("harmonic_analysis")
   , symbols()
{}



Staff::HarmonicAnalysis::~HarmonicAnalysis()
{}



float Staff::HarmonicAnalysis::get_height()
{
   return 0.9;
}



std::vector<std::pair<BeatCoordinate, HarmonicAnalysisSymbol>> Staff::HarmonicAnalysis::get_symbols_in_measure(int barline_num)
{
   std::vector<std::pair<BeatCoordinate, HarmonicAnalysisSymbol>> result = {};

   for (unsigned i=0; i<symbols.size(); i++)
      if (symbols[i].coordinate.get_barline_num() == barline_num)
         result.push_back(std::pair<BeatCoordinate, HarmonicAnalysisSymbol>(symbols[i].coordinate.get_beat_coordinate(), symbols[i].symbol));

   return result;
}



void Staff::HarmonicAnalysis::set_symbol(GridHorizontalCoordinate coordinate, HarmonicAnalysisSymbol symbol)
{
   symbols.push_back({ coordinate, symbol });
}



