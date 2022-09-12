#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class MoveCursorRight : public Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      MoveCursorRight(UI::GridEditor::Widget *grid_editor);
      ~MoveCursorRight();

      bool execute() override;
   };
}



