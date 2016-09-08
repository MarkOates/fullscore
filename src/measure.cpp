
// empty

#include <fullscore/measure.h>
#include <fullscore/note.h>
#include <allegro_flare/useful.h>


int Measure::get_note_position(Note *note)
{
	for (unsigned i=0; i<notes.size(); i++)
		if (note == &notes[i]) return i;
	return -1;
}


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


bool Measure::insert(int at_index, Note note)
{
   at_index = limit<int>(0, notes.size()-1, at_index);
	notes.insert(notes.begin() + at_index, note);
	return true;
}


bool Measure::push(Note note)
{
	notes.push_back(note);
	return true;
}


