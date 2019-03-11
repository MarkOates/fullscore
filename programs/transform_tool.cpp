


#include <allegro_flare/allegro_flare.h>

#include <fullscore/models/measures/basic.h>
#include <fullscore/models/NoteSet.h>
#include <fullscore/transforms/AddDotTransform.h>



int main(int argv, char **argc)
{
   NoteSet note_set({ { 0 }, { 1 } });

   Measure::Basic measure_before_transform(note_set.get_notes());

   return 0;
}



