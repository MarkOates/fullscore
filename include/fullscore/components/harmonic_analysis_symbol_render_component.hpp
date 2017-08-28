#pragma once



#include <fullscore/models/harmonic_analysis_symbol.h>



class HarmonicAnalysisSymbolRenderComponent
{
private:
   HarmonicAnalysisSymbol symbol;
   float x;
   float y;

public:
   HarmonicAnalysisSymbolRenderComponent(float x, float y, HarmonicAnalysisSymbol symbol);
   void render();
};



