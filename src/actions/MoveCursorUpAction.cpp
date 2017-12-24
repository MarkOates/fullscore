



#include <fullscore/actions/MoveCursorUpAction.h>

#include <fullscore/widgets/GridEditor.h>
#include <fullscore/Action.h>




Action::MoveCursorUp::MoveCursorUp(UIGridEditor *grid_editor)
   : Base(Action::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
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




