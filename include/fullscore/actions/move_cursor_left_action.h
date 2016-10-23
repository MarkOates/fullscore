#ifndef __FULLSCORE_MOVE_CURSOR_LEFT_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_LEFT_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class GUIScoreEditor;

namespace Action
{
   class MoveCursorLeft : public Base
   {
   private:
      GUIScoreEditor *score_editor;

   public:
      MoveCursorLeft(GUIScoreEditor *score_editor);
      ~MoveCursorLeft();
      bool execute() override;
   };
}




#endif
