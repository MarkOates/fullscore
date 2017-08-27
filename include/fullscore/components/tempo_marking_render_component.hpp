#pragma once



#include <allegro5/allegro_font.h>
#include <fullscore/models/tempo_marking.hpp>



class TempoMarkingRenderComponent
{
private:
   ALLEGRO_FONT *font;
   TempoMarking tempo_marking;
   float x;
   float y;

public:
   TempoMarkingRenderComponent(ALLEGRO_FONT *font, float x, float y, const TempoMarking &tempo_marking);
   ~TempoMarkingRenderComponent();

   void render();
};



