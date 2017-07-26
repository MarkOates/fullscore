#pragma once



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



