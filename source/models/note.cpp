


#include <fullscore/models/note.h>



Note::Note(int _scale_degree, int _duration, int _dots)
	: scale_degree(_scale_degree)
	, accidental(0)
	, duration(_duration)
	, is_rest(false)
	, dots(_dots)
{}




Note::~Note()
{}




