#pragma once



#include <fullscore/actions/action_base.h>



class UIGridEditor;

namespace Action
{
   class MoveCursorLeft : public Base
   {
   private:
      UIGridEditor *score_editor;

   public:
      MoveCursorLeft(UIGridEditor *score_editor);
      ~MoveCursorLeft();
      bool execute() override;
   };
}



