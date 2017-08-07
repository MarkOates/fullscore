#pragma once




#include <fullscore/actions/action_base.h>




class UIMeasureGridEditor;

namespace Action
{
   class ToggleShowDebugData : public Base
   {
   private:
      UIMeasureGridEditor *grid_editor;

   public:
      ToggleShowDebugData(UIMeasureGridEditor *grid_editor);
      ~ToggleShowDebugData();

      bool execute() override;
   };
};




