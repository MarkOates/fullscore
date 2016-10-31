#pragma once




#include <fullscore/actions/action_base.h>




class GUIScoreEditor;

namespace Action
{
   class ToggleEditModeTarget : public Base
   {
   private:
      GUIScoreEditor *gui_score_editor;

   public:
      ToggleEditModeTarget(GUIScoreEditor *gui_score_editor);
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};




