



#include <fullscore/models/Playback/PlaybackControl.hpp>

#include <fullscore/helpers/DurationHelper.hpp>




PlaybackControl::PlaybackControl()
   : position(0)
   , playing(false)
   , tempo_duration(4) // quarter note
   , tempo_bpm(120)
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




