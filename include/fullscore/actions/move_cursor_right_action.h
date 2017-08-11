#pragma once



#include <fullscore/actions/base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorRight : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorRight(UIGridEditor *grid_editor);
      ~MoveCursorRight();

      bool execute() override;
   };
}



