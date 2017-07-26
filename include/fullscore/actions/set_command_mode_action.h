#pragma once




#include <fullscore/actions/action_base.h>

#include <fullscore/widgets/gui_score_editor.h>




class UICommandBar;

namespace Action
{
   class SetCommandMode : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;
      UICommandBar *command_bar;

   public:
      SetCommandMode(UIMeasureGridEditor *score_editor, UICommandBar *command_bar);
      ~SetCommandMode();
      bool execute() override;
   };
}




