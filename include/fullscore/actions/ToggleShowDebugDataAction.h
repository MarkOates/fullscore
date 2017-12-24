#pragma once



#include <fullscore/actions/Base.h>



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


