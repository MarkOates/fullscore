#ifndef __FULLSCORE_PLAYBACK_DEVICE_INTERFACE_HEADER
#define __FULLSCORE_PLAYBACK_DEVICE_INTERFACE_HEADER




#include <string>



class PlaybackDeviceInterface
{
public:
	PlaybackDeviceInterface();
	~PlaybackDeviceInterface();

	virtual void note_on(int channel, int pitch, int velocity) = 0;
	virtual void note_off(int channel, int pitch) = 0;
	virtual void patch_change(int channel, int patch_num) = 0;
	virtual void all_notes_off() = 0;
};




#endif