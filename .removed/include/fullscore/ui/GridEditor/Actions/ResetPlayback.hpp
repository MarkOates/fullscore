#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class ResetPlayback : public Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      ResetPlayback(UI::GridEditor::Widget *grid_editor);
      ~ResetPlayback();

      bool execute() override;
   };
}



