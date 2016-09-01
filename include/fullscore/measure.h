#ifndef __FULLSCORE_MEASURE_HEADER
#define __FULLSCORE_MEASURE_HEADER




#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Note;


class Measure
{
public:
	std::vector<Note *> notes;

	int get_note_position(Note *note); // returns -1 if not found
	Note *get_note_at(int index); // returns NULL if not found
   float get_length_to_note(int index);

	// todo:
	bool insert(int index, Note *note);
	bool push(Note *note);
	int remove(int index);

	void retrograde();
	void append(const Measure &other_measure);
	void prepend(const Measure &other_measure);
	void invert(int axis);
	void double_duration();
	void half_duration();

	void transpose(int transposition);
};




#endif