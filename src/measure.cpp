
// empty

#include <fullscore/measure.h>
#include <fullscore/note.h>
#include <allegro_flare/useful.h>


Note *Measure::operator[](int index)
{
	if (index < 0 || notes.empty() || index >= notes.size()) return NULL;
	return &notes[index];
}


