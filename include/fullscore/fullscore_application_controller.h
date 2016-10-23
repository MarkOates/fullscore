#ifndef __FULLSCORE_FULLSCORE_APPLICATION_CONTROLLER
#define __FULLSCORE_FULLSCORE_APPLICATION_CONTROLLER




#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/command_bar.h>
#include <fullscore/gui_score_editor.h>
#include <fullscore/mixer.h>
#include <fullscore/playback_device_generic.h>




class FullscoreApplicationController : public UIScreen
{
public:
   SimpleNotificationScreen *simple_notification_screen;

   GUIScoreEditor *score_editor;
   UICommandBar *command_bar;
   UIMixer *gui_mixer;
   UIFramedWindow *help_window;
   Measure yank_measure_buffer;
   bool showing_help_menu;

   FullscoreApplicationController(Display *display);
   void create_help_window();
   void primary_timer_func() override;
   void key_down_func() override;
   void on_message(UIWidget *sender, std::string message) override;
};




#endif
