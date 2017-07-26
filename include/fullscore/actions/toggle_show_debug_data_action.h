#pragma once




#include <fullscore/actions/action_base.h>




class UIMeasureGridEditor;

namespace Action
{
   class ToggleShowDebugData : public Base
   {
   private:
      UIMeasureGridEditor *measure_grid_editor;

   public:
      ToggleShowDebugData(UIMeasureGridEditor *measure_grid_editor);
      ~ToggleShowDebugData();

      bool execute() override;
   };
};




