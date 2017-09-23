#pragma once



#include <fullscore/models/harmonic_analysis_symbol.h>



struct ALLEGRO_FONT;



class HarmonicAnalysisSymbolRenderComponent
{
private:
   HarmonicAnalysisSymbol symbol;
   ALLEGRO_FONT *font;
   float x;
   float y;

public:
   HarmonicAnalysisSymbolRenderComponent(ALLEGRO_FONT *font, float x, float y, HarmonicAnalysisSymbol symbol);
   void render();
};



