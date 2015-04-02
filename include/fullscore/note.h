#ifndef __FULLSCORE_NOTE_HEADER
#define __FULLSCORE_NOTE_HEADER




#include <fullscore/note.h>


class Note
{
public:
	int scale_degree;
	int duration;
	bool is_rest;
	bool attacked, released;
	float start_time, end_time;

	Note(int _scale_degree=0, int _duration=4);
	float get_duration_width();
};




#endif