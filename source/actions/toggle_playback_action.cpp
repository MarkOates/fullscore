



#include <fullscore/actions/toggle_playback_action.h>

#include <fullscore/playback_control.h>




Action::TogglePlayback::TogglePlayback(PlaybackControl *playback_control)
   : Base("toggle_playback")
{
}




Action::TogglePlayback::~TogglePlayback()
{
}




bool Action::TogglePlayback::execute()
{
   if (!playback_control) return false;

   // toggle playback
   playback_control->toggle_playback();

   return true;
}




