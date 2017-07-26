#pragma once



#include <allegro_flare/allegro_flare.h>



class UICommandBar : public UIWidget
{
public:
   UITextInput *text_input;

   UICommandBar(UIWidget *parent);
   void set_time(double time_in_sec);
   void on_draw() override;
   void on_message(UIWidget *sender, std::string message) override;
   void on_key_down() override;
};




