#pragma once



#include <allegro_flare/gui/gui_screen.h>
#include <allegro_flare/screens/simple_notification_screen.h>
#include <allegro_flare/config.h>
#include <allegro_flare/keyboard_command_mapper.h>
#include <fullscore/actions/base.h>
#include <fullscore/actions/queue_action.h>
//#include <fullscore/widgets/command_bar.h>
#include <fullscore/widgets/follow_camera.h>
#include <fullscore/widgets/grid_editor.h>
//#include <fullscore/widgets/measure_inspector.h>



class AppController : public UIScreen
{
public:
   Config &config;
   SimpleNotificationScreen *simple_notification_screen;
   Action::Queue action_queue;
   UIFollowCamera follow_camera;
   UIGridEditor *current_grid_editor;
   std::vector<UIGridEditor *> grid_editors;
   //UICommandBar *command_bar;
   //UIMeasureInspector *ui_measure_inspector;
   Measure::Basic yank_measure_buffer;
   bool showing_help_menu;
   KeyboardCommandMapper normal_mode_keyboard_mappings;
   KeyboardCommandMapper normal_mode_note_keyboard_mappings;
   KeyboardCommandMapper normal_mode_measure_keyboard_mappings;

   AppController(Display *display, Config &config);
   void key_char_func() override;
   void on_message(UIWidget *sender, std::string message) override;

   std::vector<std::string> find_action_mapping(UIGridEditor::mode_t mode, UIGridEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift=false, bool ctrl=false, bool alt=false);

   UIGridEditor *create_new_grid_editor(std::string identifier);
   bool set_current_grid_editor(UIGridEditor *editor);
   UIGridEditor *get_next_grid_editor();

   void set_keyboard_input_mappings();
};



