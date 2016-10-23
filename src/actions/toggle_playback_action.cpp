



#include <fullscore/actions/toggle_playback_action.h>

#include <fullscore/gui_score_editor.h>
#include <fullscore/mixer.h>




Action::TogglePlayback::TogglePlayback(GUIScoreEditor *score_editor, UIMixer *ui_mixer)
   : Base("toggle_playback")
   , score_editor(score_editor)
   , ui_mixer(ui_mixer)
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




