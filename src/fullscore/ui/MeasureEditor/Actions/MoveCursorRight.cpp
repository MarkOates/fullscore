

#include <fullscore/UI/MeasureEditor/Actions/MoveCursorRight.hpp>

#include <fullscore/UI/MeasureEditor/Actions.hpp>
#include <fullscore/UI/MeasureEditor/Widget.hpp>


namespace UI::MeasureEditor::Actions
{


MoveCursorRight::MoveCursorRight(UI::MeasureEditor::Widget *widget)
   : ::Action::Base(Actions::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER)
   , widget(widget)
{
}


MoveCursorRight::~MoveCursorRight()
{
}


bool MoveCursorRight::execute()
{
   if (!widget) return false;

   if (widget->is_note_target_mode()) widget->move_note_cursor_x(1);

   return true;
}


} // namespace UI::MeasureEditor::Actions


