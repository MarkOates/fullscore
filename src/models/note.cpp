


#include <fullscore/models/note.h>



Note::Note(int _scale_degree, Duration duration)
	: pitch(Pitch(_scale_degree, 0))
	, duration(duration)
	, is_rest(false)
{}




Note::~Note()
{}




bool Note::operator==(const Note &other) const
{
   return (pitch == other.pitch
         && duration == other.duration
         && is_rest == other.is_rest);
}




