#ifndef __FULLSCORE_MOVE_CURSOR_RIGHT_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_RIGHT_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class GUIScoreEditor;

namespace Action
{
   class MoveCursorRight : public Base
   {
   private:
      GUIScoreEditor *score_editor;

   public:
      MoveCursorRight(GUIScoreEditor *score_editor);
      ~MoveCursorRight();
      bool execute() override;
   };
}




#endif
