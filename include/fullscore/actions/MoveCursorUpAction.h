#pragma once



#include <fullscore/actions/Base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorUp : public Base
   {
   private:
      UIGridEditor *grid_editor;

   public:
      MoveCursorUp(UIGridEditor *grid_editor);
      ~MoveCursorUp();

      bool execute() override;
   };
}



