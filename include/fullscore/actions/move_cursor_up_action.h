#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorUp : public Base
   {
   private:
      UIGridEditor *score_editor;

   public:
      MoveCursorUp(UIGridEditor *score_editor);
      ~MoveCursorUp();
      bool execute() override;
   };
}



