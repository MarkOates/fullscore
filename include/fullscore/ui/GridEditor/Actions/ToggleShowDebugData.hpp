#pragma once



#include <fullscore/actions/Base.h>



namespace UI::GridEditor { class Widget; }

namespace UI::GridEditor::Actions
{
   class ToggleShowDebugData : public ::Action::Base
   {
   private:
      UI::GridEditor::Widget *grid_editor;

   public:
      ToggleShowDebugData(UI::GridEditor::Widget *grid_editor);
      ~ToggleShowDebugData();

      bool execute() override;
   };
};



