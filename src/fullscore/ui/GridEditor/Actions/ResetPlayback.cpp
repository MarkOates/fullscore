



#include <fullscore/UI/GridEditor/Actions/ResetPlayback.hpp>

//#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/GridEditor/Widget.hpp>



namespace UI::GridEditor::Actions
{


ResetPlayback::ResetPlayback(UI::GridEditor::Widget *grid_editor)
   : ::Action::Base("reset_playback")
   , grid_editor(grid_editor)
{
}




ResetPlayback::~ResetPlayback()
{
}




bool ResetPlayback::execute()
{
   if (!grid_editor) return false;

   grid_editor->playback_control.reset();

   return false;
}


} // namespace UI::GridEditor::Actions



