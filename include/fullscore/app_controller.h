#pragma once



#include <allegro_flare/screens/simple_notification_screen.h>

#include <fullscore/actions/action_base.h>
#include <fullscore/actions/queue_action.h>
#include <fullscore/models/reference_cursor.h>
#include <fullscore/widgets/command_bar.h>
#include <fullscore/widgets/follow_camera.h>
#include <fullscore/widgets/measure_grid_editor.h>
#include <fullscore/widgets/measure_inspector.h>



class AppController : public UIScreen
{
public:
   SimpleNotificationScreen *simple_notification_screen;

   Action::Queue action_queue;
   UIFollowCamera follow_camera;
   UIMeasureGridEditor *current_measure_grid_editor;
   std::vector<UIMeasureGridEditor *> measure_grid_editors;
   UICommandBar *command_bar;
   UIMeasureInspector *ui_measure_inspector;
   Measure::Basic yank_measure_buffer;
   bool showing_help_menu;
   ReferenceCursor reference_cursor;

   AppController(Display *display);
   void primary_timer_func() override;
   void key_char_func() override;
   void on_message(UIWidget *sender, std::string message) override;

   Action::Base *create_action(std::string action_name);

   std::string find_action_identifier(UIMeasureGridEditor::mode_t mode, UIMeasureGridEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift=false, bool ctrl=false, bool alt=false);

   UIMeasureGridEditor *create_new_score_editor(std::string identifier);
   bool set_current_measure_grid_editor(UIMeasureGridEditor *editor);
   UIMeasureGridEditor *get_next_measure_grid_editor();
};



