#pragma once



#include <fullscore/actions/Base.h>



class Motion;

namespace UI::GridEditor::Actions
{
   class StartMotion : public Base
   {
   private:
      Motion *motion;
      float *value;
      float destination;
      float duration;

   public:
      StartMotion(Motion *motion, float *value, float destination, float duration);
      ~StartMotion();

      bool execute() override;
   };
};



