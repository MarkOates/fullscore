



#include <fullscore/components/time_signature_render_component.h>

#include <sstream>
#include <fullscore/models/time_signature.h>
#include <allegro_flare/framework.h>




TimeSignatureRenderComponent::TimeSignatureRenderComponent(TimeSignature *time_signature)
   : time_signature(time_signature)
{}




TimeSignatureRenderComponent::~TimeSignatureRenderComponent()
{}




void TimeSignatureRenderComponent::render(float x, float y)
{
   std::stringstream numerator, denominator;
   numerator << time_signature->numerator;
   denominator << time_signature->denominator_duration;

   al_draw_text(Framework::font("DroidSans.ttf 20"), color::black, x, y-8, ALLEGRO_ALIGN_CENTER, numerator.str().c_str());
   al_draw_text(Framework::font("DroidSans.ttf 20"), color::black, x, y+8, ALLEGRO_ALIGN_CENTER, denominator.str().c_str());
}




