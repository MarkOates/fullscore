#ifndef __FULLSCORE_TIME_SIGNATURE_RENDER_COMPONENT_HEADER
#define __FULLSCORE_TIME_SIGNATURE_RENDER_COMPONENT_HEADER




class TimeSignature;

class TimeSignatureRenderComponent
{
private:
   TimeSignature *time_signature;

public:
   TimeSignatureRenderComponent(TimeSignature *time_signature);
   ~TimeSignatureRenderComponent();

   void render(float x, float y);
};




#endif
