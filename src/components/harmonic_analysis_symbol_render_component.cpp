


#include <fullscore/components/harmonic_analysis_symbol_render_component.hpp>

#include <allegro5/allegro_font.h>
#include <allegro_flare/color.h>
#include <sstream>



HarmonicAnalysisSymbolRenderComponent::HarmonicAnalysisSymbolRenderComponent(ALLEGRO_FONT *font, float x, float y, HarmonicAnalysisSymbol symbol)
   : symbol(symbol)
   , font(font)
   , x(x)
   , y(y)
{}



void HarmonicAnalysisSymbolRenderComponent::render()
{
   if (!font) throw std::invalid_argument("Cannot render HarmonicAnalysisSymbol with a nullptr font");
   std::stringstream ss;

   ss << symbol.fundamental.scale_degree
      << ":" << symbol.fundamental.accidental
      << ":" << HarmonicAnalysisSymbol::get_chord_quality_string(symbol.chord_quality);

   al_draw_text(font, color::black, x, y, ALLEGRO_ALIGN_CENTER, ss.str().c_str());
}



