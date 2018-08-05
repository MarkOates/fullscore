



#include <fullscore/UI/GridEditor/Actions/MoveCursorRight.hpp>

#include <fullscore/widgets/GridEditor.h>




Action::MoveCursorRight::MoveCursorRight(UIGridEditor *grid_editor)
   : ::Action::Base("move_cursor_right")
   , grid_editor(grid_editor)
{
}




Action::MoveCursorRight::~MoveCursorRight()
{
}




bool Action::MoveCursorRight::execute()
{
   if (!grid_editor) return false;

   if (grid_editor->is_measure_target_mode())
   {
      grid_editor->move_grid_cursor_x(1);
      grid_editor->note_cursor_x = 0;
   }
   else if (grid_editor->is_note_target_mode()) grid_editor->move_note_cursor_x(1);

   return true;
}




