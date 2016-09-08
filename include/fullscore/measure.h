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
   Note *operator[](int index);
};




#endif
