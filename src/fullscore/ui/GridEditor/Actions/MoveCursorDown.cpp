



#include <fullscore/UI/GridEditor/Actions/MoveCursorDown.hpp>

#include <fullscore/widgets/GridEditor.h>




Action::MoveCursorDown::MoveCursorDown(UIGridEditor *grid_editor)
   : ::Action::Base("move_cursor_down")
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




