



#include <fullscore/UI/GridEditor/Actions/MoveCursorDown.hpp>

//#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Widget.hpp>



namespace UI::GridEditor::Actions
{


MoveCursorDown::MoveCursorDown(UI::GridEditor::Widget *grid_editor)
   : ::Action::Base("move_cursor_down")
   , grid_editor(grid_editor)
{
}




MoveCursorDown::~MoveCursorDown()
{
}




bool MoveCursorDown::execute()
{
   if (!grid_editor) return false;

   grid_editor->move_grid_cursor_y(1);

   return true;
}


} // namespace UI::GridEditor::Actions


