#pragma once



#include <fullscore/actions/base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorDown : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorDown(UIGridEditor *grid_editor);
      ~MoveCursorDown();
      bool execute() override;
   };
}



