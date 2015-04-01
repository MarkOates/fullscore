



#include <fullscore/note.h>
#include <fullscore/globals.h>



Note::Note(int _scale_degree, int _duration)
	: scale_degree(_scale_degree)
	, duration(_duration)
	, is_rest(false)
{}



float Note::get_width()
{
	return (MEASURE_WIDTH/4.0f) * 4 / duration;
}



