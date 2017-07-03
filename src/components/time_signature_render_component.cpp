



#include <fullscore/components/time_signature_render_component.h>

#include <sstream>
#include <fullscore/models/time_signature.h>
#include <allegro_flare/fonts/font_bravura.h>
#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>
#include <allegro_flare/useful.h>




int __number_to_unicode(int number)
{
   if (number < 0 || number > 9) return 0;
   return bravura::number_0 + number;
}




TimeSignatureRenderComponent::TimeSignatureRenderComponent(TimeSignature *time_signature)
   : time_signature(time_signature)
{}




TimeSignatureRenderComponent::~TimeSignatureRenderComponent()
{}




void TimeSignatureRenderComponent::render(float x, float y)
{
   ALLEGRO_FONT *bravura = Framework::font("Bravura.otf 40");
   float ascent = al_get_font_ascent(bravura);

   draw_unicode_char(bravura, color::black, __number_to_unicode(time_signature->get_numerator()), ALLEGRO_ALIGN_CENTER, x, y-ascent - 10);
   draw_unicode_char(bravura, color::black, __number_to_unicode(time_signature->get_denominator().denominator), ALLEGRO_ALIGN_CENTER, x, y-ascent + 10);
}




