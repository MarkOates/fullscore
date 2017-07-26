#ifndef __FULLSCORE_MOVE_CURSOR_DOWN_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_DOWN_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class UIMeasureGridEditor;

namespace Action
{
   class MoveCursorDown : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;

   public:
      MoveCursorDown(UIMeasureGridEditor *score_editor);
      ~MoveCursorDown();
      bool execute() override;
   };
}




#endif
