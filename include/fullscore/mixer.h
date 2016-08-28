#ifndef __FULLSCORE_UI_MIXER
#define __FULLSCORE_UI_MIXER




#include <allegro_flare/allegro_flare.h>
#include <allegro_flare/gui/widget.h>




class UIMixer : public UIFramedWindow
{
public:
	class Channel
	{
	public:
		int channel_num;
		int patch;
		Channel(int channel_num, int patch);
	};

private:
	class GUIPatchTextInput : public UITextInput
	{
	public:
		int channel_num;
		GUIPatchTextInput(UIWidget *parent, int channel_num, float x, float y);
		void on_change() override;
	};

	std::vector<Channel> channels;

public:
	UIMixer(UIWidget *parent, float x_, float y_, int num_channels=8);
	Channel *get_channel(int channel_num);
	int get_patch_num(int channel_num);
};




#endif
