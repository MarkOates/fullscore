



#include <fullscore/actions/toggle_edit_mode_target_action.h>

#include <fullscore/widgets/grid_editor.h>




Action::ToggleEditModeTarget::ToggleEditModeTarget(UIMeasureGridEditor *grid_editor)
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




