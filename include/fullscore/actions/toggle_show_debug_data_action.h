#pragma once




#include <fullscore/actions/action_base.h>




class UIMeasureGridEditor;

namespace Action
{
   class ToggleShowDebugData : public Base
   {
   private:
      UIMeasureGridEditor *gui_score_editor;

   public:
      ToggleShowDebugData(UIMeasureGridEditor *gui_score_editor);
      ~ToggleShowDebugData();

      bool execute() override;
   };
};




