#pragma once




#include <fullscore/actions/action_base.h>

#include <fullscore/gui_score_editor.h>




class UICommandBar;

namespace Action
{
   class SetCommandMode : public Base
   {
   private:
      GUIScoreEditor *score_editor;
      UICommandBar *command_bar;

   public:
      SetCommandMode(GUIScoreEditor *score_editor, UICommandBar *command_bar);
      ~SetCommandMode();
      bool execute() override;
   };
}




