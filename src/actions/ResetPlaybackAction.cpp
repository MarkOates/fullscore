



#include <fullscore/actions/ResetPlaybackAction.h>

#include <fullscore/widgets/GridEditor.h>




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





