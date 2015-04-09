


#include <fullscore/playback_control.h>

#include <fullscore/note.h>





class PitchTransform
{
public:
	static int diatonic_in_c(int scale_degree, int accidental)
		// given a diatonic scale degree (zero-based index, so scale
		// degree ^1 is pitch==0, scale degree ^4 is pitch==3 and so on)
		// returns the current MIDI pitch where pitch==0 is MIDDLE_C
	{
		int octave = 0;
		while (scale_degree < 0) { scale_degree += 7; octave--; }
		while (scale_degree >= 7) { scale_degree -= 7; octave++; }
		int normalized_scale_degree = scale_degree % 7;

		switch(normalized_scale_degree)
		{
		case 0: normalized_scale_degree = 0; break;
		case 1: normalized_scale_degree = 2; break;
		case 2: normalized_scale_degree = 4; break;
		case 3: normalized_scale_degree = 5; break;
		case 4: normalized_scale_degree = 7; break;
		case 5: normalized_scale_degree = 9; break;
		case 6: normalized_scale_degree = 11; break;
		default: break;
		}

		return normalized_scale_degree + octave * 12 + accidental;
	}
	static int diatonic_in_c_alto_clef(int scale_degree, int accidental)
	{
		// this translates it so that what is on the staff is in treble_clef
		return diatonic_in_c(scale_degree, accidental);
	}
};





PlaybackControl::PlaybackControl(MeasureGrid *measure_grid, PlaybackDeviceInterface *playback_device)
	: position(0)
	, playing(false)
	, tempo_bpm(120)
	, tempo_duration(4) // quarter note
	, measure_grid(measure_grid)
	, playback_device(playback_device)
{}




void PlaybackControl::reset()
{
	position = 0;
	playing = false;
	if (!measure_grid) return;

	// reset all the notes
	//     it would be nice if it could look something more like this:
	//     ("SELECT * FROM NOTES WHERE score_id=current").each( { |note| note.on=false; note.off=false; } );
	// but alas...
	for (int x=0; x<measure_grid->get_num_measures(); x++)
		for (int y=0; y<measure_grid->get_num_staves(); y++)
		{
			Measure *measure = measure_grid->get_measure(x, y);
			for (unsigned n=0; n<measure->notes.size(); n++)
			{
				Note *note = measure->notes[n];
				note->attacked = false;
				note->released = false;
			}
		}
}




void PlaybackControl::update(double time_now)
{
	if (!playing) return;

	float CURRENT_TIMER_BPM = 60.0f;
	position += (tempo_bpm / 60.0f / CURRENT_TIMER_BPM / tempo_duration);

	// cycle through the notes, if they're past the attack points, then attack or release them
	for (int x=0; x<measure_grid->get_num_measures(); x++)
		for (int y=0; y<measure_grid->get_num_staves(); y++)
		{
			Measure *measure = measure_grid->get_measure(x, y);
			for (unsigned n=0; n<measure->notes.size(); n++)
			{
				Note &note = *measure->notes[n];
				if (note.released) continue;

				if (!note.attacked && position >= note.start_time)
				{
					// attack the note
					note.attacked = true;
					if (playback_device && !note.is_rest)
						playback_device->note_on(y, PitchTransform::diatonic_in_c_alto_clef(note.scale_degree, note.accidental), 127);
				}

				if (note.attacked && position >= note.end_time)
				{
					// release the note
					note.released = true;
					if (playback_device && !note.is_rest)
						playback_device->note_off(y, PitchTransform::diatonic_in_c_alto_clef(note.scale_degree, note.accidental));
				}
			}
		}
}




void PlaybackControl::refresh_note_start_and_end_times()
{
	// cycle through the notes
	for (int x=0; x<measure_grid->get_num_measures(); x++)
		for (int y=0; y<measure_grid->get_num_staves(); y++)
		{
			Measure *measure = measure_grid->get_measure(x, y);
			float x_cursor = 0;
			for (unsigned n=0; n<measure->notes.size(); n++)
			{
				Note &note = *measure->notes[n];
				note.start_time = x_cursor + x;
				note.end_time = note.start_time + note.get_duration_width();
				x_cursor += note.get_duration_width();
			}
		}
}




void PlaybackControl::toggle_playback()
{
	refresh_note_start_and_end_times();
	playing = !playing;
	if (!playing) playback_device->all_notes_off();
}

