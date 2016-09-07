#ifndef __FULLSCORE_NOTE_HEADER
#define __FULLSCORE_NOTE_HEADER




#include <string>
#include <vector>
#include <fullscore/note.h>
#include <fullscore/note_playback_info.h>


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
	std::string get_as_string(int format=0);
	bool set_from_string(std::string str, int format_version=0);
};




#endif
