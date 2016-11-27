#ifndef __FULLSCORE_NOTE_HEADER
#define __FULLSCORE_NOTE_HEADER




class Note
{
public:
	int scale_degree;
	int accidental;
	int duration;
	int dots;
	int is_rest;

	Note(int _scale_degree=0, int _duration=4, int _dots=0);
	~Note();
};




#endif
