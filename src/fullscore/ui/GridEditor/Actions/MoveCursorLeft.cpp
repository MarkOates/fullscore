



#include <fullscore/UI/GridEditor/Actions/MoveCursorLeft.hpp>

//#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Widget.hpp>



namespace UI::GridEditor::Actions
{


MoveCursorLeft::MoveCursorLeft(UI::GridEditor::Widget *grid_editor)
   : ::Action::Base("move_cursor_left")
   , grid_editor(grid_editor)
{
}




MoveCursorLeft::~MoveCursorLeft()
{
}




bool MoveCursorLeft::execute()
{
   if (!grid_editor) return false;

   if (grid_editor->is_measure_target_mode())
   {
      grid_editor->move_grid_cursor_x(-1);
      grid_editor->note_cursor_x = 0;
   }
   else if (grid_editor->is_note_target_mode()) grid_editor->move_note_cursor_x(-1);

   return true;
}


} // namespace UI::GridEditor::Actions


