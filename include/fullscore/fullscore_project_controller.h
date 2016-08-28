#ifndef __FULLSCORE_FULLSCORE_PROJECT_CONTROLLER
#define __FULLSCORE_FULLSCORE_PROJECT_CONTROLLER




#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/command_bar.h>
#include <fullscore/gui_score_editor.h>
#include <fullscore/mixer.h>
#include <fullscore/playback_device_generic.h>




class FullscoreProjectController : public UIScreen
{
public:
   SimpleNotificationScreen *simple_notification_screen;

   GUIScoreEditor *score_editor;
   UICommandBar *command_bar;
   UIMixer *gui_mixer;
   UIFramedWindow *help_window;
   bool showing_help_menu;

   FullscoreProjectController(Display *display);
   void create_help_window();
   void primary_timer_func() override;
   void key_down_func() override;
   void on_message(UIWidget *sender, std::string message) override;
};




#endif
