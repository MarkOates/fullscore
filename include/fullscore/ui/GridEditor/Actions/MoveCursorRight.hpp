#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;

namespace UI::GridEditor::Actions
{
   class MoveCursorRight : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorRight(UIGridEditor *grid_editor);
      ~MoveCursorRight();

      bool execute() override;
   };
}



