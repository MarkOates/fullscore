



#include <fullscore/UI/GridEditor/Actions/MoveCursorUp.hpp>

#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Actions.hpp>



namespace UI::GridEditor::Actions
{


MoveCursorUp::MoveCursorUp(UIGridEditor *grid_editor)
   : ::Action::Base(MOVE_CURSOR_UP_ACTION_IDENTIFIER)
   , grid_editor(grid_editor)
{
}




MoveCursorUp::~MoveCursorUp()
{
}




bool MoveCursorUp::execute()
{
   if (!grid_editor) return false;

   grid_editor->move_grid_cursor_y(-1);

   return true;
}


} // namespace UI::GridEditor::Actions


