#ifndef __FULLSCORE_FULLSCORE_APPLICATION_CONTROLLER
#define __FULLSCORE_FULLSCORE_APPLICATION_CONTROLLER




#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/actions/action_base.h>
#include <fullscore/actions/queue_action.h>
#include <fullscore/command_bar.h>
#include <fullscore/follow_camera.h>
#include <fullscore/gui_score_editor.h>
#include <fullscore/playback_device_generic.h>




class FullscoreApplicationController : public UIScreen
{
public:
   SimpleNotificationScreen *simple_notification_screen;

   Action::Queue action_queue;
   UIFollowCamera follow_camera;
   GUIScoreEditor *gui_score_editor;
   UICommandBar *command_bar;
   Measure yank_measure_buffer;
   bool showing_help_menu;

   FullscoreApplicationController(Display *display);
   void primary_timer_func() override;
   void key_down_func() override;
   void on_message(UIWidget *sender, std::string message) override;

   Action::Base *create_action(std::string action_name);

   std::string find_action_identifier(GUIScoreEditor::mode_t mode, int al_keycode, bool shift=false, bool alt=false);

   bool create_new_score_editor();
};




#endif
