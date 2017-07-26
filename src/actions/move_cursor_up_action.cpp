



#include <fullscore/actions/move_cursor_up_action.h>

#include <fullscore/widgets/gui_score_editor.h>




Action::MoveCursorUp::MoveCursorUp(UIMeasureGridEditor *score_editor)
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

   score_editor->move_measure_cursor_y(-1);

   return true;
}




