#pragma once



#include <fullscore/models/HarmonicAnalysisSymbol.h>



struct ALLEGRO_FONT;



class HarmonicAnalysisSymbolRenderComponent
{
private:
   HarmonicAnalysisSymbol symbol;
   ALLEGRO_FONT *large_font;
   ALLEGRO_FONT *small_font;
   float x;
   float y;

public:
   HarmonicAnalysisSymbolRenderComponent(ALLEGRO_FONT *large_font, ALLEGRO_FONT *small_font, float x, float y, HarmonicAnalysisSymbol symbol);
   void render();
};



