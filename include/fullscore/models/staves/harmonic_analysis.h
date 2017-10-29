#pragma once



#include <fullscore/models/staves/base.h>
#include <fullscore/models/grid_horizontal_coordinate.h>
#include <fullscore/models/harmonic_analysis_symbol.h>



namespace Staff
{
   class HarmonicAnalysis : public Base
   {
   private:
      class HarmonicAnalysisSymbolPlacement
      {
      public:
         GridHorizontalCoordinate coordinate;
         HarmonicAnalysisSymbol symbol;

         HarmonicAnalysisSymbolPlacement(GridHorizontalCoordinate coordinate, HarmonicAnalysisSymbol symbol);
      };

      std::vector<HarmonicAnalysisSymbolPlacement> symbols;

   public:
      HarmonicAnalysis();
      ~HarmonicAnalysis();

      virtual float get_height() override;

      std::vector<std::pair<BeatCoordinate, HarmonicAnalysisSymbol>> get_symbols_in_measure(int barline_num);
      void set_symbol(GridHorizontalCoordinate coordinate, HarmonicAnalysisSymbol symbol);
   };
};



