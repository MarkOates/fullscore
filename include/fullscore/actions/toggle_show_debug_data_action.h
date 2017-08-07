#pragma once




#include <fullscore/actions/action_base.h>




class UIGridEditor;

namespace Action
{
   class ToggleShowDebugData : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      ToggleShowDebugData(UIGridEditor *grid_editor);
      ~ToggleShowDebugData();

      bool execute() override;
   };
};




