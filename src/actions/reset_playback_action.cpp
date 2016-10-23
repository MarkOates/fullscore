



#include <fullscore/actions/reset_playback_action.h>

#include <fullscore/gui_score_editor.h>




Action::ResetPlayback::ResetPlayback(GUIScoreEditor *score_editor)
   : Base("reset_playback")
   , score_editor(score_editor)
{
}




Action::ResetPlayback::~ResetPlayback()
{
}




bool Action::ResetPlayback::execute()
{
   if (!score_editor) return false;

   score_editor->playback_control.reset();

   return false;
}





