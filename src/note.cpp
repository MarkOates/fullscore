


#include <sstream>
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




std::string Note::get_as_string(int format_version)
{
	std::stringstream ss;
	if (format_version == 0)
	{
		ss << scale_degree << " " << accidental << " " << duration << " " << dots << " " << is_rest;
	}
	return ss.str();
}




bool Note::set_from_string(std::string str, int format_version)
{
	if (format_version == 0)
	{
		std::stringstream ss;
		ss << str;
		ss >> scale_degree >> accidental >> duration >> dots >> is_rest;
		return true;
	}
}
