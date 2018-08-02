#pragma once



#include <allegro_flare/gui/gui_screen.h>
#include <allegro_flare/screens/simple_notification_screen.h>
#include <allegro_flare/config.h>
#include <allegro_flare/keyboard_command_mapper.h>
#include <fullscore/models/lists/PlotterList.hpp>
#include <fullscore/actions/Base.h>
#include <fullscore/actions/QueueAction.h>
//#include <fullscore/widgets/CommandBar.h>
#include <fullscore/widgets/CommandBar.h>
#include <fullscore/widgets/FollowCamera.h>
#include <fullscore/widgets/GridEditor.h>
#include <fullscore/UI/PlotterList/Widget.hpp>
//#include <fullscore/widgets/MeasureInspector.h>



class AppController : public UIScreen
{
public:
   Config &config;
   SimpleNotificationScreen *simple_notification_screen;
   Action::Queue action_queue;
   UIFollowCamera follow_camera;
   UIGridEditor *current_grid_editor;
   std::vector<UIGridEditor *> grid_editors;
   UICommandBar *command_bar;
   //UIMeasureInspector *ui_measure_inspector;
   PlotterList *plotter_list;
   UI::PlotterList::Widget *plotter_list_widget;
   Measure::Basic yank_measure_buffer;
   bool showing_help_menu;
   KeyboardCommandMapper grid_editor_normal_mode_keyboard_mappings;
   KeyboardCommandMapper grid_editor_normal_mode_note_keyboard_mappings;
   KeyboardCommandMapper grid_editor_normal_mode_measure_keyboard_mappings;

   AppController(Display *display, Config &config);
   void key_char_func() override;

   std::vector<std::string> find_grid_editor_action_mapping(UIGridEditor::mode_t mode, UIGridEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift=false, bool ctrl=false, bool alt=false);

   UIGridEditor *create_new_grid_editor(std::string identifier);
   bool set_current_grid_editor(UIGridEditor *editor);
   UIGridEditor *get_next_grid_editor();

   void set_keyboard_grid_editor_input_mappings();
};



