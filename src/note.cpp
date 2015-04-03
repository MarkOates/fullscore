



#include <fullscore/note.h>



Note::Note(int _scale_degree, int _duration)
	: scale_degree(_scale_degree)
	, duration(_duration)
	, is_rest(false)
	, attacked(false)
	, released(false)
	, start_time(0)
	, end_time(0)
{}



float Note::get_duration_width()
{
	return 1.0f / duration;
}



