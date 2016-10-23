#ifndef __FULLSCORE_MOVE_CURSOR_DOWN_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_DOWN_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class GUIScoreEditor;

namespace Action
{
   class MoveCursorDown : public Base
   {
   private:
      GUIScoreEditor *score_editor;

   public:
      MoveCursorDown(GUIScoreEditor *score_editor);
      ~MoveCursorDown();
      bool execute() override;
   };
}




#endif
