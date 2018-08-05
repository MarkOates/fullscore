#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;

namespace UI::GridEditor::Actions
{
   class MoveCursorUp : public Action::Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorUp(UIGridEditor *grid_editor);
      ~MoveCursorUp();

      bool execute() override;
   };
}



