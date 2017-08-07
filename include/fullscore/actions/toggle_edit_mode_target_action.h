#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class ToggleEditModeTarget : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      ToggleEditModeTarget(UIGridEditor *grid_editor);
      ~ToggleEditModeTarget();

      bool execute() override;
   };
};



