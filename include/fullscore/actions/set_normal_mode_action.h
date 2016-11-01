#pragma once




#include <fullscore/actions/action_base.h>

#include <fullscore/gui_score_editor.h>




class UICommandBar;

namespace Action
{
   class SetNormalMode : public Base
   {
   private:
      GUIScoreEditor *score_editor;
      UICommandBar *command_bar;

   public:
      SetNormalMode(GUIScoreEditor *score_editor, UICommandBar *command_bar);
      ~SetNormalMode();
      bool execute() override;
   };
}




