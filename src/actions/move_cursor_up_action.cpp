



#include <fullscore/actions/move_cursor_up_action.h>

#include <fullscore/widgets/grid_editor.h>




Action::MoveCursorUp::MoveCursorUp(UIGridEditor *grid_editor)
   : Base("move_cursor_up")
   , grid_editor(grid_editor)
{
}




Action::MoveCursorUp::~MoveCursorUp()
{
}




bool Action::MoveCursorUp::execute()
{
   if (!grid_editor) return false;

   grid_editor->move_measure_cursor_y(-1);

   return true;
}




