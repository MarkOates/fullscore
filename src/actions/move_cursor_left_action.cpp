



#include <fullscore/actions/move_cursor_left_action.h>

#include <fullscore/gui_score_editor.h>




Action::MoveCursorLeft::MoveCursorLeft(GUIScoreEditor *score_editor)
   : Base("move_cursor_left")
   , score_editor(score_editor)
{
}




Action::MoveCursorLeft::~MoveCursorLeft()
{
}




bool Action::MoveCursorLeft::execute()
{
   if (!score_editor) return false;

   if (score_editor->is_measure_mode())
   {
      score_editor->move_measure_cursor_x(-1);
      score_editor->note_cursor_x = 0;
   }
   else if (score_editor->is_note_mode()) score_editor->move_note_cursor_x(-1);

   return false;
}



