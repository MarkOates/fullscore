



#include <fullscore/UI/GridEditor/Actions/ToggleEditModeTarget.hpp>

//#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Widget.hpp>



namespace UI::GridEditor::Actions
{


ToggleEditModeTarget::ToggleEditModeTarget(UI::GridEditor::Widget *grid_editor)
   : ::Action::Base("toggle_edit_mode_target")
   , grid_editor(grid_editor)
{}




ToggleEditModeTarget::~ToggleEditModeTarget()
{}




bool ToggleEditModeTarget::execute()
{
   if (!grid_editor) return false;

   grid_editor->toggle_edit_mode_target();

   return true;
}


} // namespace UI::GridEditor::Actions


