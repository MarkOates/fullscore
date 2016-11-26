


#include <fullscore/pitch_projector.h>



PitchProjector::PitchProjector(ProjectionSet projection_set, IndexSet index_set)
   : projection_set(projection_set)
   , index_set(index_set)
{}



IndexSet PitchProjector::get_projection()
{
   IndexSet result({});

   for (auto &index_element : index_set.pitches)
   {
      ProjectionPitch pitch(0);

      int local_index = index_element.pitch % projection_set.pitches.size();
      pitch.pitch = projection_set.pitches[local_index].pitch;
      pitch.extension = index_element.pitch / projection_set.extension + index_element.extension;

      result.pitches.push_back(pitch);
   }

   return result;
}


/*
class PitchProjectionTransform
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
*/




