#ifndef __FULLSCORE_MUSIC_ENGRAVER
#define __FULLSCORE_MUSIC_ENGRAVER




#include <allegro_flare/render_music_notation.h>
#include <fullscore/models/note.h>
#include <fullscore/models/measures/basic.h>


class MusicEngraver
{
public:
	DrawingInterface *drawing_interface;
	MusicNotation music_notation;
	MusicEngraver();
	std::string translate_note_to_str(const Note &note);
	void draw(Measure::BasicMeasure *measure, float x, float y, const float whole_note_width);
};




#endif
