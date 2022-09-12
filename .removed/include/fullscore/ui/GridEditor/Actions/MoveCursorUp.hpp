#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class MoveCursorUp : public Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      MoveCursorUp(UI::GridEditor::Widget *grid_editor);
      ~MoveCursorUp();

      bool execute() override;
   };
}



