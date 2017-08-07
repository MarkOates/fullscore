#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;
class Motion;

namespace Action
{
   class SetScoreZoom : public Base
   {
   private:
      UIGridEditor *grid_editor;
      Motion *motion;
      float destination;
      float duration;

   public:
      SetScoreZoom(UIGridEditor *grid_editor, Motion *motion, float destination, float duration);
      ~SetScoreZoom();

      bool execute() override;
   };
};



