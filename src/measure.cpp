
// empty

#include <fullscore/measure.h>
#include <fullscore/note.h>


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


void Measure::retrograde()
{
	std::vector<Note *> result;
	for (unsigned i=notes.size()-1; i>=0; i--)
		result.push_back(notes[i]);
	notes = result;
}


void Measure::append(const Measure &other_measure)
{
	for (unsigned i=0; i<other_measure.notes.size(); i++)
		notes.push_back(other_measure.notes[i]);
}


void Measure::prepend(const Measure &other_measure)
{
	Measure result_measure;
	result_measure.append(other_measure);
	result_measure.append(*this);
	notes = result_measure.notes;
}


void Measure::invert(int axis)
{
	for (unsigned i=0; i<notes.size(); i++)
		notes[i]->scale_degree = (notes[i]->scale_degree - axis) * -1 + axis;
}


void Measure::double_duration()
{
	// warning, there need to be limits in this function
	for (unsigned i=0; i<notes.size(); i++)
		notes[i]->duration /= 2;
}


void Measure::half_duration()
{
	// warning, there need to be limits in this function
	for (unsigned i=0; i<notes.size(); i++)
		notes[i]->duration *= 2;
}



