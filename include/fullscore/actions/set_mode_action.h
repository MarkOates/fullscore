#pragma once



#include <fullscore/actions/action_base.h>

#include <fullscore/widgets/grid_editor.h>



class UICommandBar;

namespace Action
{
   class SetMode : public Base
   {
   private:
      UIGridEditor *score_editor;
      UICommandBar *command_bar;
      UIGridEditor::mode_t mode;

   public:
      SetMode(UIGridEditor *score_editor, UICommandBar *command_bar, UIGridEditor::mode_t mode);
      ~SetMode();
      bool execute() override;
   };
}



