#pragma once




#include <fullscore/actions/action_base.h>




class GUIScoreEditor;

namespace Action
{
   class ToggleShowDebugData : public Base
   {
   private:
      GUIScoreEditor *gui_score_editor;

   public:
      ToggleShowDebugData(GUIScoreEditor *gui_score_editor);
      ~ToggleShowDebugData();

      bool execute() override;
   };
};




