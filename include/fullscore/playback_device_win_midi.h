#ifndef __FULLSCORE_PLAYBACK_DEVICE_WIN_MIDI_HEADER
#define __FULLSCORE_PLAYBACK_DEVICE_WIN_MIDI_HEADER




#include <fullscore/playback_device_interface.h>



class PlaybackDeviceWinMIDI : public PlaybackDeviceInterface
{
public:
	PlaybackDeviceWinMIDI();
	~PlaybackDeviceWinMIDI();

	void note_on(int channel, int pitch, int velocity);
	void note_off(int channel, int pitch);
	void patch_change(int channel, int patch_num);
	void all_notes_off();
};




#endif