#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorLeft : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorLeft(UIGridEditor *grid_editor);
      ~MoveCursorLeft();
      bool execute() override;
   };
}



