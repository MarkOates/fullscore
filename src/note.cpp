



#include <fullscore/note.h>



Note::Note(int _scale_degree, int _duration, int _dots)
	: scale_degree(_scale_degree)
	, accidental(0)
	, duration(_duration)
	, is_rest(false)
	, attacked(false)
	, released(false)
	, start_time(0)
	, end_time(0)
	, dots(_dots)
{}



float Note::get_duration_width()
{
	return 1.0f / duration;
}



