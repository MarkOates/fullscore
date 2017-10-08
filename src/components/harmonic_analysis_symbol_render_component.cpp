


#include <fullscore/components/harmonic_analysis_symbol_render_component.hpp>

#include <allegro5/allegro_font.h>
#include <allegro_flare/useful.h>
#include <allegro_flare/color.h>



HarmonicAnalysisSymbolRenderComponent::HarmonicAnalysisSymbolRenderComponent(ALLEGRO_FONT *large_font, ALLEGRO_FONT *small_font, float x, float y, HarmonicAnalysisSymbol symbol)
   : symbol(symbol)
   , large_font(large_font)
   , small_font(small_font)
   , x(x)
   , y(y)
{}



void HarmonicAnalysisSymbolRenderComponent::render()
{
   if (!large_font) throw std::invalid_argument("Cannot render HarmonicAnalysisSymbol with a nullptr large_font");
   if (!small_font) throw std::invalid_argument("Cannot render HarmonicAnalysisSymbol with a nullptr small_font");

   std::string roman_numeral_string = HarmonicAnalysisSymbol::get_roman_numeral_string(symbol.fundamental.scale_degree, symbol.chord_quality);
   std::string accidental = HarmonicAnalysisSymbol::get_accidental_string(symbol.fundamental.accidental);
   std::string quality_symbol = HarmonicAnalysisSymbol::get_chord_quality_symbol_string(symbol.chord_quality);

   float roman_numeral_text_width = al_get_text_width(large_font, roman_numeral_string.c_str());
   float line_height = al_get_font_line_height(large_font);

   al_draw_text(large_font, color::black, x, y, ALLEGRO_ALIGN_CENTER, roman_numeral_string.c_str());
   al_draw_text(small_font, color::black, x-roman_numeral_text_width/2, y, ALLEGRO_ALIGN_RIGHT, accidental.c_str());
   al_draw_text(small_font, color::black, x+roman_numeral_text_width/2, y, ALLEGRO_ALIGN_LEFT, quality_symbol.c_str());
}



