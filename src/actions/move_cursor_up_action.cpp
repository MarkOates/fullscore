



#include <fullscore/actions/move_cursor_up_action.h>

#include <fullscore/gui_score_editor.h>




Action::MoveCursorUp::MoveCursorUp(GUIScoreEditor *score_editor)
   : Base("move_cursor_up")
   , score_editor(score_editor)
{
}




Action::MoveCursorUp::~MoveCursorUp()
{
}




bool Action::MoveCursorUp::execute()
{
   if (!score_editor) return false;

   return false;
}




