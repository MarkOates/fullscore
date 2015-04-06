
// empty

#include <fullscore/measure.h>

int Measure::get_note_position(Note *note)
{
	for (unsigned i=0; i<notes.size(); i++)
		if (note == notes[i]) return i;
	return -1;
}


Note *Measure::get_note_at(int index)
{
	if (index < 0 || notes.empty() || index >= notes.size()) return NULL;
	return notes[index];
}