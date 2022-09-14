#pragma once


#include <allegro_flare/gui/gui_screen.h>
#include <allegro_flare/screens/simple_notification_screen.h>
#include <allegro_flare/config.h>
#include <allegro_flare/keyboard_command_mapper.h>
#include <fullscore/models/lists/PlotterList.hpp>
#include <fullscore/actions/Base.h>
#include <fullscore/actions/QueueAction.h>
#include <fullscore/widgets/CommandBar.h>
#include <fullscore/widgets/FollowCamera.h>
#include <fullscore/ui/GridEditor/Widget.hpp>
#include <fullscore/ui/PlotterList/Widget.hpp>


class AppController : public UIScreen
{
public:
   Config &config;
   SimpleNotificationScreen *simple_notification_screen;
   Action::Queue action_queue;
   UIFollowCamera follow_camera;
   UI::GridEditor::Widget *current_grid_editor_widget;
   std::vector<UI::GridEditor::Widget *> grid_editor_widgets;
   UICommandBar *command_bar;
   PlotterList *plotter_list;
   UI::PlotterList::Widget *plotter_list_widget;
   Measure::Basic yank_measure_buffer;
   bool showing_help_menu;

   AppController(Display *display, Config &config);
   void key_char_func() override;

   UI::GridEditor::Widget *create_new_grid_editor(std::string identifier);
   bool set_current_grid_editor_widget(UI::GridEditor::Widget *editor);
   UI::GridEditor::Widget *get_next_grid_editor_widget();

   void set_keyboard_grid_editor_input_mappings();
};


