#pragma once



#include <fullscore/actions/base.h>

#include <fullscore/widgets/grid_editor.h>



class UICommandBar;

namespace Action
{
   class SetNormalMode : public Base
   {
   private:
      UIGridEditor *grid_editor;
      UICommandBar *command_bar;

   public:
      SetNormalMode(UIGridEditor *grid_editor, UICommandBar *command_bar);
      ~SetNormalMode();
      bool execute() override;
   };
}



