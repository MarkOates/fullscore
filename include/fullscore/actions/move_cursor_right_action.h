#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorRight : public Base
   {
   private:
      UIGridEditor *score_editor;

   public:
      MoveCursorRight(UIGridEditor *score_editor);
      ~MoveCursorRight();
      bool execute() override;
   };
}



