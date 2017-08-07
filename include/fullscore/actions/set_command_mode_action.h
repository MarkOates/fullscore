#pragma once




#include <fullscore/actions/action_base.h>

#include <fullscore/widgets/grid_editor.h>




class UICommandBar;

namespace Action
{
   class SetCommandMode : public Base
   {
   private:
      UIGridEditor *score_editor;
      UICommandBar *command_bar;

   public:
      SetCommandMode(UIGridEditor *score_editor, UICommandBar *command_bar);
      ~SetCommandMode();
      bool execute() override;
   };
}




