



#include <fullscore/actions/move_cursor_left_action.h>

#include <fullscore/widgets/grid_editor.h>




Action::MoveCursorLeft::MoveCursorLeft(UIGridEditor *grid_editor)
   : Base("move_cursor_left")
   , grid_editor(grid_editor)
{
}




Action::MoveCursorLeft::~MoveCursorLeft()
{
}




bool Action::MoveCursorLeft::execute()
{
   if (!grid_editor) return false;

   if (grid_editor->is_measure_target_mode())
   {
      grid_editor->move_grid_cursor_x(-1);
      grid_editor->note_cursor_x = 0;
   }
   else if (grid_editor->is_note_target_mode()) grid_editor->move_note_cursor_x(-1);

   return true;
}




