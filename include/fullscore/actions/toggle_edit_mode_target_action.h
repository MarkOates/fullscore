#pragma once




#include <fullscore/actions/action_base.h>




class UIMeasureGridEditor;

namespace Action
{
   class ToggleEditModeTarget : public Base
   {
   private:
      UIMeasureGridEditor *gui_score_editor;

   public:
      ToggleEditModeTarget(UIMeasureGridEditor *gui_score_editor);
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};




