#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorDown : public Base
   {
   private:
      UIGridEditor *score_editor;

   public:
      MoveCursorDown(UIGridEditor *score_editor);
      ~MoveCursorDown();
      bool execute() override;
   };
}



