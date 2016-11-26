


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
      int local_extension = index_element.pitch / projection_set.pitches.size();

      pitch.pitch = projection_set.pitches[local_index].pitch;
      pitch.pitch += local_extension * projection_set.extension;

      result.pitches.push_back(pitch);
   }

   return result;
}



