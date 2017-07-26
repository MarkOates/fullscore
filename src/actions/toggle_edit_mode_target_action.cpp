



#include <fullscore/actions/toggle_edit_mode_target_action.h>

#include <fullscore/widgets/gui_score_editor.h>




Action::ToggleEditModeTarget::ToggleEditModeTarget(GUIScoreEditor *gui_score_editor)
   : Base("toggle_edit_mode_target")
   , gui_score_editor(gui_score_editor)
{}




Action::ToggleEditModeTarget::~ToggleEditModeTarget()
{}




bool Action::ToggleEditModeTarget::execute()
{
   if (!gui_score_editor) return false;

   gui_score_editor->toggle_edit_mode_target();

   return true;
}




