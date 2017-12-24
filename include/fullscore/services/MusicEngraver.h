#ifndef __FULLSCORE_MUSIC_ENGRAVER
#define __FULLSCORE_MUSIC_ENGRAVER




#include <allegro_flare/render_music_notation.h>
#include <allegro_flare/color.h>
#include <fullscore/models/Note.h>
#include <fullscore/models/measures/Basic.h>


class MusicEngraver
{
public:
	DrawingInterface *drawing_interface;
	MusicNotation music_notation;
	MusicEngraver();
	std::string translate_note_to_str(const Note &note);
	void draw(Measure::Base *measure, float x, float y, const float whole_note_width, ALLEGRO_COLOR notation_color=color::null_color, ALLEGRO_COLOR staff_color=color::null_color);
};




#endif
