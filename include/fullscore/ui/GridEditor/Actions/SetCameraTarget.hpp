#pragma once



#include <fullscore/actions/Base.h>



class UIFollowCamera;

namespace UI::GridEditor::Actions
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



