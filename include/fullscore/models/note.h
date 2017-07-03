#ifndef __FULLSCORE_NOTE_HEADER
#define __FULLSCORE_NOTE_HEADER



#include <fullscore/models/duration.h>



class Note
{
public:
	int scale_degree;
	int accidental;
	Duration duration;
	int is_rest;

	Note(int _scale_degree=0, Duration duration = Duration());
	~Note();

   bool operator==(const Note &other) const;
};




#endif
