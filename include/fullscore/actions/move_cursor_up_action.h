#ifndef __FULLSCORE_MOVE_CURSOR_UP_ACTION_HEADER
#define __FULLSCORE_MOVE_CURSOR_UP_ACTION_HEADER




#include <fullscore/actions/action_base.h>



class GUIScoreEditor;

namespace Action
{
   class MoveCursorUp : public Base
   {
   private:
      GUIScoreEditor *score_editor;

   public:
      MoveCursorUp(GUIScoreEditor *score_editor);
      ~MoveCursorUp();
      bool execute() override;
   };
}




#endif
