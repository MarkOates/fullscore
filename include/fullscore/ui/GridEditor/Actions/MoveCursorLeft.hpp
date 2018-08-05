#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;

namespace UI::GridEditor::Actions
{
   class MoveCursorLeft : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorLeft(UIGridEditor *grid_editor);
      ~MoveCursorLeft();

      bool execute() override;
   };
}



