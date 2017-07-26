



#include <fullscore/models/playback_control.h>

#include <fullscore/helpers/duration_helper.h>




PlaybackControl::PlaybackControl()
   : position(0)
   , playing(false)
   , tempo_bpm(120)
   , tempo_duration(4) // quarter note
{}




void PlaybackControl::reset()
{
   position = 0;
   playing = false;
}




void PlaybackControl::update(double time_now)
{
   if (!playing) return;

   float CURRENT_TIMER_BPM = 60.0f;
   position += (tempo_bpm / 60.0f / CURRENT_TIMER_BPM / tempo_duration);
}




void PlaybackControl::toggle_playback()
{
   playing = !playing;
}



