#pragma once



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



