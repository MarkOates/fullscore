



#include <fullscore/actions/move_cursor_down_action.h>

#include <fullscore/widgets/measure_grid_editor.h>




Action::MoveCursorDown::MoveCursorDown(UIMeasureGridEditor *score_editor)
   : Base("move_cursor_down")
   , score_editor(score_editor)
{
}




Action::MoveCursorDown::~MoveCursorDown()
{
}




bool Action::MoveCursorDown::execute()
{
   if (!score_editor) return false;

   score_editor->move_measure_cursor_y(1);

   return true;
}




