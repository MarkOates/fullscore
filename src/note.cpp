


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




float Note::get_duration_width()
{
	float width = 1.0f / duration;
	float dots_percentage = 0.0f;
	float previous_ammount = 1.0f;
	for (int i=0; i<(int)dots; i++)
	{
		previous_ammount *= 0.5f;
		dots_percentage += previous_ammount;
	}

	return width + width * dots_percentage;
}




