


#include <fullscore/components/tempo_marking_render_component.hpp>

#include <allegro_flare/color.h>



TempoMarkingRenderComponent::TempoMarkingRenderComponent(ALLEGRO_FONT *font, float x, float y, const TempoMarking &tempo_marking)
   : font(font)
   , tempo_marking(tempo_marking)
   , x(x)
   , y(y)
{
   if (font == nullptr) throw std::invalid_argument("Cannot create a TempoMarkingRenderComponent with a nullptr font");
}



TempoMarkingRenderComponent::~TempoMarkingRenderComponent()
{}



void TempoMarkingRenderComponent::render()
{
   std::stringstream tempo_string;

   tempo_string << tempo_marking.duration.denominator;
   for (unsigned i=0; i<tempo_marking.duration.dots; i++)
      tempo_string << ".";
   tempo_string << " = " << tempo_marking.bpm;

   al_draw_text(font, color::black, x, y, ALLEGRO_ALIGN_LEFT, tempo_string.str().c_str());
}



