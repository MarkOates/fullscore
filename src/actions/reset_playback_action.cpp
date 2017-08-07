



#include <fullscore/actions/reset_playback_action.h>

#include <fullscore/widgets/grid_editor.h>




Action::ResetPlayback::ResetPlayback(UIGridEditor *grid_editor)
   : Base("reset_playback")
   , grid_editor(grid_editor)
{
}




Action::ResetPlayback::~ResetPlayback()
{
}




bool Action::ResetPlayback::execute()
{
   if (!grid_editor) return false;

   grid_editor->playback_control.reset();

   return false;
}





