#pragma once



#include <fullscore/actions/Base.h>

#include <fullscore/widgets/GridEditor.h>



class UICommandBar;

namespace UI::GridEditor::Actions
{
   class SetNormalMode : public ::Action::Base
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



