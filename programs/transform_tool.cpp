


#include <allegro_flare/allegro_flare.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/converters/stream_operators/NoteStreamOperators.h>
#include <fullscore/models/NoteSet.h>
#include <fullscore/transforms/AddDotTransform.h>



int main(int argv, char **argc)
{
   NoteSet note_set({ { 0 }, { 1 } });
   NoteSet result_notes_set{{}};

   result_notes_set.get_notes_ref() = Transform::AddDot().transform(note_set.get_notes());

   Measure::Basic measure_before_transform(note_set.get_notes());
   Measure::Basic measure_after_transform(result_notes_set.get_notes());

   std::cout << "before transform:" << std::endl;
   for (auto &note : measure_before_transform.get_notes_copy())
      std::cout << note << std::endl;

   std::cout << "after transform:" << std::endl;
   for (auto &note : measure_after_transform.get_notes_copy())
      std::cout << note << std::endl;

   return 0;
}



