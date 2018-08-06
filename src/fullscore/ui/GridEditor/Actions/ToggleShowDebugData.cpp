



#include <fullscore/UI/GridEditor/Actions/ToggleShowDebugData.hpp>

//#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Widget.hpp>


namespace UI::GridEditor::Actions
{


ToggleShowDebugData::ToggleShowDebugData(UI::GridEditor::Widget *grid_editor)
   : ::Action::Base("toggle_show_debug_data")
   , grid_editor(grid_editor)
{}




ToggleShowDebugData::~ToggleShowDebugData()
{}




bool ToggleShowDebugData::execute()
{
   if (!grid_editor) return false;

   grid_editor->showing_debug_data = !grid_editor->showing_debug_data;

   return true;
}

} // namespace UI::GridEditor::Actions



