#ifndef __FULLSCORE_COMMAND_BAR
#define __FULLSCORE_COMMAND_BAR




#include <allegro_flare/allegro_flare.h>




class UICommandBar : public UIWidget
{
public:
   UIScaledText *time;
   UIButton *play_button;
   UIButton *rewind_button;
   UITextInput *text_input;

   UICommandBar(UIWidget *parent);
   void set_time(double time_in_sec);
   void on_draw() override;
   void on_message(UIWidget *sender, std::string message) override;
   void on_key_down() override;
};




#endif
