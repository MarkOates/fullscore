



#include <fullscore/actions/MoveCursorDownAction.h>

#include <fullscore/widgets/GridEditor.h>




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

   grid_editor->move_grid_cursor_y(1);

   return true;
}




