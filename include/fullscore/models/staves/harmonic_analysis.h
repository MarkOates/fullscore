#pragma once



#include <fullscore/models/staves/base.h>
#include <fullscore/models/grid_horizontal_coordinate.h>
#include <fullscore/models/harmonic_analysis_symbol.h>



namespace Staff
{
   class HarmonicAnalysis : public Base
   {
   private:
      int num_columns;

      class HarmonicAnalysisSymbolPlacement
      {
      public:
         HarmonicAnalysisSymbol symbol;
         GridHorizontalCoordinate coordinate;

         HarmonicAnalysisSymbolPlacement(HarmonicAnalysisSymbol symbol, GridHorizontalCoordinate coordinate);
      };

      std::vector<HarmonicAnalysisSymbolPlacement> symbols;

   public:
      HarmonicAnalysis(int num_columns);
      ~HarmonicAnalysis();

      virtual int get_num_columns() override;
      virtual float get_height() override;

      virtual Measure::Base *get_measure(int column_num) override;
      virtual bool set_column(int column_num, Measure::Base *measure) override;
      virtual bool insert_column(int at_index, Measure::Base *measure) override;
      virtual bool erase_column(int at_index) override;
      virtual bool append_column(Measure::Base *measure) override;

      std::vector<std::pair<BeatCoordinate, HarmonicAnalysisSymbol>> get_symbols_in_measure(int measure_num);
      void set_symbol(HarmonicAnalysisSymbol symbol, GridHorizontalCoordinate coordinate);
   };
};



