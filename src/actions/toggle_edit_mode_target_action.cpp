



#include <fullscore/actions/toggle_edit_mode_target_action.h>

#include <fullscore/widgets/measure_grid_editor.h>




Action::ToggleEditModeTarget::ToggleEditModeTarget(UIMeasureGridEditor *measure_grid_editor)
   : Base("toggle_edit_mode_target")
   , measure_grid_editor(measure_grid_editor)
{}




Action::ToggleEditModeTarget::~ToggleEditModeTarget()
{}




bool Action::ToggleEditModeTarget::execute()
{
   if (!measure_grid_editor) return false;

   measure_grid_editor->toggle_edit_mode_target();

   return true;
}




