



#include <fullscore/UI/GridEditor/Actions/ToggleEditModeTarget.hpp>

#include <fullscore/widgets/GridEditor.h>



namespace UI::GridEditor::Actions
{


ToggleEditModeTarget::ToggleEditModeTarget(UIGridEditor *grid_editor)
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


