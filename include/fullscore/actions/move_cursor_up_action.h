#ifndef __FULLSCORE_MOVE_CURSOR_UP_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_UP_ACTION_HEADER




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




#endif
