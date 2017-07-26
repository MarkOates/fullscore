#ifndef __FULLSCORE_MOVE_CURSOR_LEFT_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_LEFT_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class UIMeasureGridEditor;

namespace Action
{
   class MoveCursorLeft : public Base
   {
   private:
      UIMeasureGridEditor *score_editor;

   public:
      MoveCursorLeft(UIMeasureGridEditor *score_editor);
      ~MoveCursorLeft();
      bool execute() override;
   };
}




#endif
