



#include <fullscore/actions/ToggleEditModeTargetAction.h>

#include <fullscore/widgets/GridEditor.h>




Action::ToggleEditModeTarget::ToggleEditModeTarget(UIGridEditor *grid_editor)
   : Base("toggle_edit_mode_target")
   , grid_editor(grid_editor)
{}




Action::ToggleEditModeTarget::~ToggleEditModeTarget()
{}




bool Action::ToggleEditModeTarget::execute()
{
   if (!grid_editor) return false;

   grid_editor->toggle_edit_mode_target();

   return true;
}




