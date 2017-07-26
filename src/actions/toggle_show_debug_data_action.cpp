



#include <fullscore/actions/toggle_show_debug_data_action.h>

#include <fullscore/widgets/measure_grid_editor.h>



Action::ToggleShowDebugData::ToggleShowDebugData(UIMeasureGridEditor *measure_grid_editor)
   : Base("toggle_show_debug_data")
   , measure_grid_editor(measure_grid_editor)
{}




Action::ToggleShowDebugData::~ToggleShowDebugData()
{}




bool Action::ToggleShowDebugData::execute()
{
   if (!measure_grid_editor) return false;

   measure_grid_editor->showing_debug_data = !measure_grid_editor->showing_debug_data;

   return true;
}




