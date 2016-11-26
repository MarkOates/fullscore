



#include <fullscore/playback_control.h>

#include <fullscore/helpers/duration_helper.h>




class PitchTransform
{
public:
   static int diatonic_in_c(int scale_degree, int accidental)
      // given a diatonic scale degree (zero-based index, so scale
      // degree ^1 is pitch==0, scale degree ^4 is pitch==3 and so on)
      // returns the current MIDI pitch where pitch==0 is MIDDLE_C
   {
      int octave = 0;
      while (scale_degree < 0) { scale_degree += 7; octave--; }
      while (scale_degree >= 7) { scale_degree -= 7; octave++; }
      int normalized_scale_degree = scale_degree % 7;

      switch(normalized_scale_degree)
      {
         case 0: normalized_scale_degree = 0; break;
         case 1: normalized_scale_degree = 2; break;
         case 2: normalized_scale_degree = 4; break;
         case 3: normalized_scale_degree = 5; break;
         case 4: normalized_scale_degree = 7; break;
         case 5: normalized_scale_degree = 9; break;
         case 6: normalized_scale_degree = 11; break;
         default: break;
      }

      return normalized_scale_degree + octave * 12 + accidental;
   }
   static int diatonic_in_c_alto_clef(int scale_degree, int accidental)
   {
      // this translates it so that what is on the staff is in treble_clef
      return diatonic_in_c(scale_degree, accidental);
   }
};




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




