#pragma once



#include <fullscore/actions/Base.h>

#include <fullscore/widgets/GridEditor.h>



class UICommandBar;

namespace Action
{
   class SetMode : public Base
   {
   private:
      UIGridEditor *grid_editor;
      UICommandBar *command_bar;
      UIGridEditor::mode_t mode;

   public:
      SetMode(UIGridEditor *grid_editor, UICommandBar *command_bar, UIGridEditor::mode_t mode);
      ~SetMode();

      bool execute() override;
   };
}



