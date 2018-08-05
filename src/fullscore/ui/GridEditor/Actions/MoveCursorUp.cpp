



#include <fullscore/UI/GridEditor/Actions/MoveCursorUp.hpp>

#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Actions.hpp>




Action::MoveCursorUp::MoveCursorUp(UIGridEditor *grid_editor)
   : ::Action::Base(Action::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
   , grid_editor(grid_editor)
{
}




Action::MoveCursorUp::~MoveCursorUp()
{
}




bool Action::MoveCursorUp::execute()
{
   if (!grid_editor) return false;

   grid_editor->move_grid_cursor_y(-1);

   return true;
}




