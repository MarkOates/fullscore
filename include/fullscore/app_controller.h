#pragma once



#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/actions/action_base.h>
#include <fullscore/actions/queue_action.h>
#include <fullscore/models/reference_cursor.h>
#include <fullscore/widgets/command_bar.h>
#include <fullscore/widgets/follow_camera.h>
#include <fullscore/widgets/gui_score_editor.h>
#include <fullscore/widgets/measure_inspector.h>
#include <fullscore/playback_device_generic.h>




class AppController : public UIScreen
{
public:
   SimpleNotificationScreen *simple_notification_screen;

   Action::Queue action_queue;
   UIFollowCamera follow_camera;
   GUIScoreEditor *current_gui_score_editor;
   std::vector<GUIScoreEditor *> gui_score_editors;
   UICommandBar *command_bar;
   UIMeasureInspector *ui_measure_inspector;
   Measure::Basic yank_measure_buffer;
   bool showing_help_menu;
   ReferenceCursor reference_cursor;

   AppController(Display *display);
   void primary_timer_func() override;
   void key_down_func() override;
   void on_message(UIWidget *sender, std::string message) override;

   Action::Base *create_action(std::string action_name);

   std::string find_action_identifier(GUIScoreEditor::mode_t mode, GUIScoreEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift=false, bool ctrl=false, bool alt=false);

   GUIScoreEditor *create_new_score_editor(std::string identifier);
   bool set_current_gui_score_editor(GUIScoreEditor *editor);
   GUIScoreEditor *get_next_gui_score_editor();
};



