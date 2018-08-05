#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class MoveCursorDown : public Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      MoveCursorDown(UI::GridEditor::Widget *grid_editor);
      ~MoveCursorDown();

      bool execute() override;
   };
}



