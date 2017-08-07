#pragma once




#include <fullscore/actions/action_base.h>




class UIMeasureGridEditor;

namespace Action
{
   class ToggleEditModeTarget : public Base
   {
   private:
      UIMeasureGridEditor *grid_editor;

   public:
      ToggleEditModeTarget(UIMeasureGridEditor *grid_editor);
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};




