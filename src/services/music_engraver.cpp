



#include <allegro_flare/useful.h>
#include <allegro_flare/drawing_interfaces/drawing_interface_allegro5.h>

#include <fullscore/helpers/duration_helper.h>
#include <fullscore/models/note.h>
#include <fullscore/services/music_engraver.h>




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

	//if (note.playback_info.released) result += "{ color=gray }";
	//else if (note.playback_info.attacked) result += "{ color=greenyellow }";

	int num_octaves = abs(note.pitch.scale_degree) / 8;
	int local_degree = abs(note.pitch.scale_degree) % 8;
	if (note.pitch.scale_degree < 0) local_degree = 8 - local_degree;
	char octave_char = (note.pitch.scale_degree < 0) ? ',' : '\'';
	int octave_offset = (note.pitch.scale_degree < 0) ? 1 : 0;

	// write the duration
	result += music_notation.duration_denominator_to_char(note.duration.denominator);

	// write the pitch (or rest)
	std::string accidental = (note.pitch.accidental == -1) ? "-" : (note.pitch.accidental == 1) ? "+" : "";
	if (note.is_rest) result += "r" + tostring(local_degree);
	else result += std::string((num_octaves+octave_offset), octave_char) + accidental + tostring(local_degree);

	// write the dots
	if (note.duration.dots != 0) result += std::string(note.duration.dots, '.');

	return result;
}



void MusicEngraver::draw(Measure::Base *measure, float x, float y, const float whole_note_width)
{
	int cursor_x = 0;
   std::vector<Note> notes = measure->get_notes_copy();
	for (unsigned i=0; i<notes.size(); i++)
	{
		music_notation.draw(x + cursor_x, y, translate_note_to_str(notes[i]));
		cursor_x += DurationHelper::get_length(notes[i].duration.denominator, notes[i].duration.dots) * whole_note_width;
	}
}



