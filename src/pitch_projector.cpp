


#include <fullscore/pitch_projector.h>



PitchProjector::PitchProjector(ProjectionSet projection_set, IndexSet index_set)
   : projection_set(projection_set)
   , index_set(index_set)
{}



IndexSet PitchProjector::get_projection()
{
   IndexSet result({});

   if (projection_set.pitches.empty() || index_set.pitches.empty()) return result;

   for (auto &index_element : index_set.pitches)
   {
      int scale_degree = index_element.scale_degree;
      int cardinality = projection_set.pitches.size();
      int extension = 0;
      Pitch pitch(0);

      while (scale_degree < 0) { scale_degree += cardinality; extension--; }
      while (scale_degree >= cardinality) { scale_degree -= cardinality; extension++; }

      Pitch &projected_pitch = projection_set.pitches[scale_degree];
      pitch.scale_degree = projected_pitch.scale_degree + extension * projection_set.extension;
      pitch.accidental = projected_pitch.accidental + index_element.accidental;

      result.pitches.push_back(pitch);
   }

   return result;
}



