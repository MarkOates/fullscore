
// empty

#include <fullscore/measure.h>
#include <fullscore/note.h>
#include <allegro_flare/useful.h>


Note *Measure::get_note_at(int index)
{
	if (index < 0 || notes.empty() || index >= notes.size()) return NULL;
	return &notes[index];
}


float Measure::get_length_to_note(int index)
{
   float sum = 0;
   if (index < 0 || index >= notes.size()) return 0;

   for (int i=0; i<index; i++)
      sum += notes[i].get_duration_width();
   return sum;
}


