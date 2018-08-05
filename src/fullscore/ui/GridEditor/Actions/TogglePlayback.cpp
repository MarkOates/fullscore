



#include <fullscore/UI/GridEditor/Actions/TogglePlayback.hpp>

#include <fullscore/models/PlaybackControl.h>




Action::TogglePlayback::TogglePlayback(PlaybackControl *playback_control)
   : ::Action::Base("toggle_playback")
   , playback_control(playback_control)
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




