#ifndef __FULLSCORE_MEASURE_HEADER
#define __FULLSCORE_MEASURE_HEADER




#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Note;


class Measure
{
public:
	std::vector<Note> notes;

	Note *get_note_at(int index); // returns NULL if not found
   float get_length_to_note(int index);
};




#endif
