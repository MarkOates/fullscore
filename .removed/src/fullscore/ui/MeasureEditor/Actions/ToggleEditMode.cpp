



#include <fullscore/UI/MeasureEditor/Actions/ToggleEditMode.hpp>

#include <fullscore/UI/MeasureEditor/Actions.hpp>
#include <fullscore/UI/MeasureEditor/Widget.hpp>



namespace UI::MeasureEditor::Actions
{


ToggleEditMode::ToggleEditMode(UI::MeasureEditor::Widget *widget)
   : ::Action::Base(Actions::TOGGLE_EDIT_MODE_ACTION_IDENTIFIER)
   , widget(widget)
{}




ToggleEditMode::~ToggleEditMode()
{}




bool ToggleEditMode::execute()
{
   if (!widget) return false;

   widget->toggle_edit_mode_target();

   return true;
}


} // namespace UI::MeasureEditor::Actions


