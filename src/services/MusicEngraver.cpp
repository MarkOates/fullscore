



#include <allegro_flare/useful.h>
#include <allegro_flare/drawing_interfaces/drawing_interface_allegro5.h>

#include <fullscore/helpers/DurationHelper.h>
#include <fullscore/models/Note.h>
#include <fullscore/services/MusicEngraver.h>




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

	int num_octaves = abs(note.pitch.get_scale_degree()) / 8;
	int local_degree = abs(note.pitch.get_scale_degree()) % 8;
	if (note.pitch.get_scale_degree() < 0) local_degree = 8 - local_degree;
	char octave_char = (note.pitch.get_scale_degree() < 0) ? ',' : '\'';
	int octave_offset = (note.pitch.get_scale_degree() < 0) ? 1 : 0;

	// write the duration
	result += music_notation.duration_denominator_to_char(note.duration.get_denominator());

	// write the pitch (or rest)
	std::string accidental = (note.pitch.get_accidental() == -1) ? "-" : (note.pitch.get_accidental() == 1) ? "+" : "";
	if (note.is_rest) result += "r" + tostring(local_degree);
	else result += std::string((num_octaves+octave_offset), octave_char) + accidental + tostring(local_degree);

	// write the dots
	if (note.duration.get_dots() != 0) result += std::string(note.duration.get_dots(), '.');

	return result;
}



void MusicEngraver::draw(Measure::Base *measure, float x, float y, const float whole_note_width, ALLEGRO_COLOR notation_color, ALLEGRO_COLOR staff_color)
{
	int cursor_x = 0;
   std::vector<Note> notes = measure->get_notes_copy();
	for (unsigned i=0; i<notes.size(); i++)
	{
      std::string notes_as_string = translate_note_to_str(notes[i]);
      if (!color::basically_equal(notation_color, color::null_color))
      {
         std::string color_as_name = al_color_rgb_to_name(notation_color.r, notation_color.g, notation_color.b);
         notes_as_string = std::string("{color=") + color_as_name + "}" + notes_as_string;
      }
      if (!color::basically_equal(staff_color, color::null_color))
      {
         std::string color_as_name = al_color_rgb_to_name(staff_color.r, staff_color.g, staff_color.b);
         notes_as_string = std::string("{staff_color=") + color_as_name + "}" + notes_as_string;
      }
		music_notation.draw(x + cursor_x, y, notes_as_string);
		cursor_x += DurationHelper::get_length(notes[i].duration) * whole_note_width;
	}
}



