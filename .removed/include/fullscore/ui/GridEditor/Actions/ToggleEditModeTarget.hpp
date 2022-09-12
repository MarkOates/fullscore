#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class ToggleEditModeTarget : public ::Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      ToggleEditModeTarget(UI::GridEditor::Widget *grid_editor);
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};



