


#include <fullscore/playback_control.h>

#include <fullscore/note.h>






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
			Measure *measure = &measure_grid->get_measure(x, y);
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
			Measure *measure = &measure_grid->get_measure(x, y);
			for (unsigned n=0; n<measure->notes.size(); n++)
			{
				Note &note = *measure->notes[n];
				if (note.released) continue;

				if (!note.attacked && position >= note.start_time)
				{
					// attack the note
					note.attacked = true;
					if (playback_device) playback_device->note_on(y, note.scale_degree + 60, 127);
				}

				if (note.attacked && position >= note.end_time)
				{
					// release the note
					note.released = true;
					if (playback_device) playback_device->note_off(y, note.scale_degree + 60);
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
			Measure *measure = &measure_grid->get_measure(x, y);
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
}

