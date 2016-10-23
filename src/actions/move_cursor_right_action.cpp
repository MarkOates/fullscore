



#include <fullscore/actions/move_cursor_right_action.h>

#include <fullscore/gui_score_editor.h>




Action::MoveCursorRight::MoveCursorRight(GUIScoreEditor *score_editor)
   : Base("move_cursor_right")
   , score_editor(score_editor)
{
}




Action::MoveCursorRight::~MoveCursorRight()
{
}




bool Action::MoveCursorRight::execute()
{
   if (!score_editor) return false;

   if (score_editor->is_measure_mode())
   {
      score_editor->move_measure_cursor_x(1);
      score_editor->note_cursor_x = 0;
   }
   else if (score_editor->is_note_mode()) score_editor->move_note_cursor_x(1);

   return false;
}




