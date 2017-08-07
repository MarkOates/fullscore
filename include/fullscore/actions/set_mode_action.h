#pragma once



#include <fullscore/actions/action_base.h>

#include <fullscore/widgets/grid_editor.h>



class UICommandBar;

namespace Action
{
   class SetMode : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;
      UICommandBar *command_bar;
      UIMeasureGridEditor::mode_t mode;

   public:
      SetMode(UIMeasureGridEditor *score_editor, UICommandBar *command_bar, UIMeasureGridEditor::mode_t mode);
      ~SetMode();
      bool execute() override;
   };
}



