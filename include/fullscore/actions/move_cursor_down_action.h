#ifndef __FULLSCORE_MOVE_CURSOR_DOWN_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_DOWN_ACTION_HEADER




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




#endif
