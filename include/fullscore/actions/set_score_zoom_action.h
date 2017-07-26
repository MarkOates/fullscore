#pragma once




#include <fullscore/actions/action_base.h>




class UIMeasureGridEditor;
class Motion;

namespace Action
{
   class SetScoreZoom : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;
      Motion *motion;
      float destination;
      float duration;

   public:
      SetScoreZoom(UIMeasureGridEditor *score_editor, Motion *motion, float destination, float duration);
      ~SetScoreZoom();

      bool execute() override;
   };
};




