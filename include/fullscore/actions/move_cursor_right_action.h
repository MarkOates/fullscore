#ifndef __FULLSCORE_MOVE_CURSOR_RIGHT_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_RIGHT_ACTION_HEADER




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




#endif
