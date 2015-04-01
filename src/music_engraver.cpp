





#include <allegro_flare/useful.h>
#include <allegro_flare/drawing_interfaces/drawing_interface_allegro5.h>

#include <fullscore/note.h>
#include <fullscore/music_engraver.h>




MusicEngraver::MusicEngraver()
	: drawing_interface(new DrawingInterfaceAllegro5())
	, music_notation(drawing_interface)
{
	music_notation.set_spacing_method(MusicNotation::SPACING_FIXED);
}



std::string MusicEngraver::translate_note_to_str(const Note &note)
	// this function needs too be worked on
{
	std::string result;

	int num_octaves = abs(note.scale_degree) / 8;
	int local_degree = abs(note.scale_degree) % 8;
	if (note.scale_degree < 0) local_degree = 8 - local_degree;
	char octave_char = (note.scale_degree < 0) ? ',' : '\'';
	int octave_offset = (note.scale_degree < 0) ? 1 : 0;
	result += music_notation.duration_denominator_to_char(note.duration) + std::string((num_octaves+octave_offset), octave_char) + tostring(local_degree);

	return result;
}



void MusicEngraver::draw(Measure *measure, float x, float y)
{
	int cursor_x = 0;
	for (unsigned i=0; i<measure->notes.size(); i++)
	{
		music_notation.draw(x + cursor_x, y, translate_note_to_str(*measure->notes[i]));
		cursor_x += measure->notes[i]->get_width();
	}
}



