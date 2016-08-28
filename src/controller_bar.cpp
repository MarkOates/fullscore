



#include <fullscore/controller_bar.h>

#include <cmath>
#include <iomanip>




UIControllerBar::UIControllerBar(UIWidget *parent)
   : UIWidget(parent, "UIControllerBar", new UISurfaceAreaBox(0, 0, parent->place.size.x, 66))
   , time(NULL)
   , play_button(NULL)
{
   this->place.align = {0.0, 0.0};

   play_button = new UIButton(this, place.size.x-20-50, place.size.y-10-20, 100, 40, "");
   play_button->attr.set("on_click_send_message", "toggle_playback");
   play_button->set_icon(Framework::bitmap("play_icon.png"));
   play_button->place.align = vec2d(0.5, 0.5);

   rewind_button = new UIButton(this, place.size.x-130-25, place.size.y-10-20, 50, 40, "");
   rewind_button->attr.set("on_click_send_message", "reset_playback");
   rewind_button->set_icon(Framework::bitmap("rewind_icon.png"));
   rewind_button->place.align = vec2d(0.5, 0.5);

   time = new UIScaledText(this, 20, place.size.y-10, "4:33.263");
   time->place.align = vec2d(0, 1.0);
   time->set_font_color(color::aliceblue);
}




void UIControllerBar::set_time(double time_in_sec)
{
   int min = (int)floor(time_in_sec / 60.0);
   int seconds = (int)floor(time_in_sec) - min;
   int msec = (time_in_sec - floor(time_in_sec)) * 1000;
   std::stringstream time_str;
   time_str << std::setfill('0');
   time_str << std::setw(2) << min << ":";
   time_str << std::setw(2) << seconds << ".";
   time_str << std::setw(3) << msec;
   time->set_text(time_str.str());
}




void UIControllerBar::on_draw()
{
   UIStyleAssets::draw_outset(0, 0, place.size.x, place.size.y);
}




void UIControllerBar::on_message(UIWidget *sender, std::string message)
{
   // right now... the message is just being passed up to the next widget
   // there is certainly a better way to do this (*cough* signals and slots)
   family.parent->on_message(sender, message);
}




