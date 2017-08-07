#pragma once




#include <fullscore/actions/action_base.h>

#include <fullscore/widgets/grid_editor.h>




class UICommandBar;

namespace Action
{
   class SetNormalMode : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;
      UICommandBar *command_bar;

   public:
      SetNormalMode(UIMeasureGridEditor *score_editor, UICommandBar *command_bar);
      ~SetNormalMode();
      bool execute() override;
   };
}




