



#include <fullscore/actions/move_cursor_left_action.h>

#include <fullscore/gui_score_editor.h>




Action::MoveCursorLeft::MoveCursorLeft(GUIScoreEditor *score_editor)
   : Base()
   , score_editor(score_editor)
{
}




Action::MoveCursorLeft::~MoveCursorLeft()
{
}




bool Action::MoveCursorLeft::execute()
{
   // unimplemented
   return false;
}




