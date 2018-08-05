#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;

namespace UI::GridEditor::Actions
{
   class ToggleEditModeTarget : public ::Action::Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      ToggleEditModeTarget(UIGridEditor *grid_editor);
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};



