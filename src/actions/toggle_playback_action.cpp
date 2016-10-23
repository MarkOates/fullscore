



#include <fullscore/actions/toggle_playback_action.h>

#include <fullscore/gui_score_editor.h>




Action::TogglePlayback::TogglePlayback(GUIScoreEditor *score_editor)
   : Base("toggle_playback")
   , score_editor(score_editor)
{
}




Action::TogglePlayback::~TogglePlayback()
{
}




bool Action::TogglePlayback::execute()
{
   if (!score_editor) return false;

   // unimplemented
   return true;
}




