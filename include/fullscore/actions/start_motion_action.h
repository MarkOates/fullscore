#pragma once




#include <fullscore/actions/action_base.h>




class Motion;

namespace Action
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




