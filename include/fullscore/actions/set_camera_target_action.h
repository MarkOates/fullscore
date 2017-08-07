#pragma once



#include <fullscore/actions/base.h>



class UIFollowCamera;

namespace Action
{
   class SetCameraTarget : public Base
   {
   private:
      UIFollowCamera *camera;
      float x, y;

   public:
      SetCameraTarget(UIFollowCamera *camera, float x, float y);
      ~SetCameraTarget();

      bool execute() override;
   };
};



