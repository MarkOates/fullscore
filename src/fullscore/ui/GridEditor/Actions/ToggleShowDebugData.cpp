



#include <fullscore/UI/GridEditor/Actions/ToggleShowDebugData.hpp>

#include <fullscore/widgets/GridEditor.h>



Action::ToggleShowDebugData::ToggleShowDebugData(UIGridEditor *grid_editor)
   : ::Action::Base("toggle_show_debug_data")
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




