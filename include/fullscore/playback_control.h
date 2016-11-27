#ifndef __FULLSCORE_PLAYBACK_CONTROL
#define __FULLSCORE_PLAYBACK_CONTROL




class PlaybackControl
{
public:
	float position; // in seconds
	bool playing;
	float tempo_duration;
	double tempo_bpm;

	PlaybackControl();

	void toggle_playback();
	void reset();
	void update(double time_now);
};




#endif
