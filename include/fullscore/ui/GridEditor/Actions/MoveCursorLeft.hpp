#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class MoveCursorLeft : public Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      MoveCursorLeft(UI::GridEditor::Widget *grid_editor);
      ~MoveCursorLeft();

      bool execute() override;
   };
}



