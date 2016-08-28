#ifndef __FULLSCORE_CONTROLLER_BAR
#define __FULLSCORE_CONTROLLER_BAR




#include <allegro_flare/allegro_flare.h>




class UIControllerBar : public UIWidget
{
public:
	UIScaledText *time;
	UIButton *play_button;
	UIButton *rewind_button;

	UIControllerBar(UIWidget *parent);
	void set_time(double time_in_sec);
   void on_draw() override;
	void on_message(UIWidget *sender, std::string message) override;
};




#endif
