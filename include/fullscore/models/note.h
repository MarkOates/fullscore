#ifndef __FULLSCORE_NOTE_HEADER
#define __FULLSCORE_NOTE_HEADER



#include <fullscore/models/duration.h>

#include <fullscore/models/pitch.h>



class Note
{
public:
   Pitch pitch;
	Duration duration;
	int is_rest;

	Note(int _scale_degree=0, Duration duration = Duration());
	~Note();

   bool operator==(const Note &other) const;
};




#endif
