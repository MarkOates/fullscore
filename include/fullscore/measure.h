#ifndef __FULLSCORE_MEASURE_HEADER
#define __FULLSCORE_MEASURE_HEADER




#include <vector>
#include <allegro5/allegro.h>

class Note;


class Measure
{
public:
	std::vector<Note *> notes;
	void draw(float x, float y, ALLEGRO_FONT *font);
};




#endif