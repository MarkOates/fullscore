#ifndef __FULLSCORE_NOTE_HEADER
#define __FULLSCORE_NOTE_HEADER




#include <string>
#include <vector>
#include <fullscore/models/note.h>
#include <fullscore/models/note_playback_info.h>


class Note
{
public:
	int scale_degree;
	int accidental;
	int duration;
	int dots;
	int is_rest;

   NotePlaybackInfo playback_info;

	Note(int _scale_degree=0, int _duration=4, int _dots=0);
	~Note();

	float get_duration_width();
};




#endif
