


#include <fullscore/models/note.h>



Note::Note(int _scale_degree, Duration duration)
	: scale_degree(_scale_degree)
	, accidental(0)
	, duration(duration)
	, is_rest(false)
{}




Note::~Note()
{}




bool Note::operator==(const Note &other) const
{
   return (scale_degree == other.scale_degree
         && accidental == other.accidental
         && duration == other.duration
         && is_rest == other.is_rest);
}




