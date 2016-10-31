#pragma once




#include <fullscore/actions/action_base.h>




class GUIScoreEditor;
class Motion;

namespace Action
{
   class SetScoreZoom : public Base
   {
   private:
      GUIScoreEditor *score_editor;
      Motion *motion;
      float destination;
      float duration;

   public:
      SetScoreZoom(GUIScoreEditor *score_editor, Motion *motion, float destination, float duration);
      ~SetScoreZoom();

      bool execute() override;
   };
};




