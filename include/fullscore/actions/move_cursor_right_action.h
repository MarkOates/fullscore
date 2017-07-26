#ifndef __FULLSCORE_MOVE_CURSOR_RIGHT_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_RIGHT_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class UIMeasureGridEditor;

namespace Action
{
   class MoveCursorRight : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;

   public:
      MoveCursorRight(UIMeasureGridEditor *score_editor);
      ~MoveCursorRight();
      bool execute() override;
   };
}




#endif
