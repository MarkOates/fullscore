#ifndef __FULLSCORE_PLAYBACK_CONTROL
#define __FULLSCORE_PLAYBACK_CONTROL





#include <fullscore/playback_device_interface.h>
#include <fullscore/models/measure_grid.h>


class PlaybackControl
{
public:
	float position; // in seconds
	bool playing;
	float tempo_duration;
	double tempo_bpm;
	MeasureGrid *measure_grid;
	PlaybackDeviceInterface *playback_device;

	PlaybackControl(MeasureGrid *measure_grid, PlaybackDeviceInterface *playback_device);

	void toggle_playback();
	void reset();
	void refresh_note_start_and_end_times();
	void update(double time_now);
};




#endif
