



#include <fullscore/actions/toggle_show_debug_data_action.h>

#include <fullscore/widgets/grid_editor.h>



Action::ToggleShowDebugData::ToggleShowDebugData(UIMeasureGridEditor *grid_editor)
   : Base("toggle_show_debug_data")
   , grid_editor(grid_editor)
{}




Action::ToggleShowDebugData::~ToggleShowDebugData()
{}




bool Action::ToggleShowDebugData::execute()
{
   if (!grid_editor) return false;

   grid_editor->showing_debug_data = !grid_editor->showing_debug_data;

   return true;
}




