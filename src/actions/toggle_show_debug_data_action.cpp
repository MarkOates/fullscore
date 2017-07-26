



#include <fullscore/actions/toggle_show_debug_data_action.h>

#include <fullscore/widgets/gui_score_editor.h>



Action::ToggleShowDebugData::ToggleShowDebugData(UIMeasureGridEditor *gui_score_editor)
   : Base("toggle_show_debug_data")
   , gui_score_editor(gui_score_editor)
{}




Action::ToggleShowDebugData::~ToggleShowDebugData()
{}




bool Action::ToggleShowDebugData::execute()
{
   if (!gui_score_editor) return false;

   gui_score_editor->showing_debug_data = !gui_score_editor->showing_debug_data;

   return true;
}




