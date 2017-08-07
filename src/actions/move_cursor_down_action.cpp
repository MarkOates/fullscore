



#include <fullscore/actions/move_cursor_down_action.h>

#include <fullscore/widgets/grid_editor.h>




Action::MoveCursorDown::MoveCursorDown(UIGridEditor *grid_editor)
   : Base("move_cursor_down")
   , grid_editor(grid_editor)
{
}




Action::MoveCursorDown::~MoveCursorDown()
{
}




bool Action::MoveCursorDown::execute()
{
   if (!grid_editor) return false;

   grid_editor->move_measure_cursor_y(1);

   return true;
}




