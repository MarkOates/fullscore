


#include <fullscore/AppController.hpp>

#include <allegro_flare/framework.h>
#include <fullscore/factories/ActionFactory.h>
#include <fullscore/factories/GridFactory.h>
#include <fullscore/factories/PlotterListWidgetActionFactory.hpp>
#include <fullscore/UI/PlotterList/ActionFactory.hpp>
#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/models/GridCoordinate.h>
#include <fullscore/models/Measure.h>
#include <fullscore/models/Staff.h>
#include <fullscore/Action.h>




#include <fullscore/transforms/RetrogradeTransform.h>
#include <fullscore/models/plotters/Basic.h>
#include <fullscore/models/plotters/Destination.h>

static void init_app_based_on_setup_config(AppController *app)
{
   if (!app) throw std::runtime_error("nullptr app!");


   // usually:
   // std::string init_template_identifier = config.get_or_default_str("FULLSCORE_SETTINGS", "init_template", "string_quartet");


   // init grid
   app->set_current_grid_editor_widget(app->create_new_grid_editor("full_score"));
   

   // init plotter list

   std::vector<Note> notes_to_plot = {
      Note(-1, Duration(Duration::QUARTER, 1)),
      Note(0, Duration(Duration::QUARTER, 1)),
      Note(1, Duration(Duration::EIGHTH)),
      Note(2, Duration(Duration::EIGHTH)),
   };

   auto notes_retrograde = Transform::Retrograde().transform(notes_to_plot);

   Grid &grid = app->current_grid_editor_widget->grid;

   //app->plotter_list->append(new Plotter::Basic(&grid, 3, notes_to_plot));
   //app->plotter_list->append(new Plotter::Basic(&grid, 5, notes_retrograde));

   app->plotter_list->append(
      new Plotter::Destination(
         { { 2, 4 }, { 5, 7 }, { 8, 4 }, }, {
         5, 6, 8
         }
      )
   );
}




AppController::AppController(Display *display, Config &config)
   : UIScreen(display)
   , config(config)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , action_queue("master_queue")
   , follow_camera(this)
   //, current_grid_editor(nullptr)
   , current_grid_editor_widget(nullptr)
   , grid_editors()
   , command_bar(new UICommandBar(this))
   //, ui_measure_inspector(new UIMeasureInspector(this))
   , plotter_list(new PlotterList)
   , plotter_list_widget(new UI::PlotterList::Widget(this, plotter_list, 300))
   , yank_measure_buffer()
   , grid_editor_normal_mode_keyboard_mappings()
   , grid_editor_normal_mode_note_keyboard_mappings()
   , grid_editor_normal_mode_measure_keyboard_mappings()
{
   UIScreen::draw_focused_outline = false;
   set_keyboard_grid_editor_input_mappings();

   init_app_based_on_setup_config(this);
   plotter_list_widget->bring_to_front();
}



void AppController::set_keyboard_grid_editor_input_mappings()
{
   //                                        keycode,               shift, ctrl,  alt,   identifier
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_G,         false, false, false, {"double_duration"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_R,         false, false, false, {"toggle_rest"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_N,         false, false, false, {"invert"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_Z,         false, false, false, {"retrograde"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_H,         false, false, false, {Action::MOVE_CURSOR_LEFT_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_J,         false, false, false, {Action::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_SEMICOLON, false, false, false, {Action::SET_COMMAND_MODE_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_MINUS,     false, false, false, {"camera_zoom_out"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_EQUALS,    false, false, false, {"camera_zoom_in"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_UP,        false, false, false, {"move_camera_up"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_DOWN,      false, false, false, {"move_camera_down"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_RIGHT,     false, false, false, {"move_camera_right"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_LEFT,      false, false, false, {"move_camera_left"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_TAB,       false, false, false, {Action::TOGGLE_EDIT_MODE_TARGET_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F2,        false, false, false, {Action::TOGGLE_SHOW_DEBUG_DATA_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_SPACE,     false, false, false, {Action::TOGGLE_PLAYBACK_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_4,         false, false, false, {"set_time_signature_numerator_4"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_5,         false, false, false, {"set_time_signature_numerator_5"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_Y,         false, false, false, {Action::YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_P,         false, false, false, {Action::PASTE_MEASURE_FROM_BUFFER_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_O,         false, false, false, {"octatonic_1"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_2,         false, false, false, {"set_time_signature_numerator_2"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_K,         false, false, false, {Action::MOVE_CURSOR_UP_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_L,         false, false, false, {Action::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_W,         false, false, false, {Action::MOVE_FLOATING_MEASURE_CURSOR_RIGHT_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_B,         true,  false, false, {Action::MOVE_FLOATING_MEASURE_CURSOR_LEFT_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_S,         false, false, false, {"half_duration"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_3,         false, false, false, {"set_time_signature_numerator_3"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F,         false, false, false, {"transpose_up"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_D,         false, false, false, {"transpose_down"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_S,         false,  true, false, {"split_note"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_7,         true,  false, false, {"set_reference_by_id_measure"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_EQUALS,    true,  false, false, {"camera_zoom_default"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_M,         false, false, false, {Action::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_3,         true,  false, false, {"set_stack_measure"});



   // measure mode commands
   grid_editor_normal_mode_measure_keyboard_mappings.set_mapping(ALLEGRO_KEY_F, false, true,  false, {"ascend"});
   grid_editor_normal_mode_measure_keyboard_mappings.set_mapping(ALLEGRO_KEY_D, false, true,  false, {"descend"});
   grid_editor_normal_mode_measure_keyboard_mappings.set_mapping(ALLEGRO_KEY_X, false, false, false, {Action::DELETE_FLOATING_MEASURE_IDENTIFIER});



   // note mode commands
   grid_editor_normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_A,        false, false, false, {"insert_note_after"});
   grid_editor_normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_X,        false, false, false, {"erase_note"});
   grid_editor_normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_I,        false, false, false, {"insert_note"});
   grid_editor_normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_COMMA,    false, false, false, {"remove_dot"});
   grid_editor_normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_FULLSTOP, false, false, false, {"add_dot_to_note"});



   // likely to be non-grid_editor actions
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_Q,         false, false, false, {Action::RESET_PLAYBACK_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F7,        false, false, false, {Action::SAVE_GRID_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F8,        false, false, false, {Action::LOAD_GRID_ACTION_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_N,         false,  true, false, {"create_new_grid_editor"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_X,         false,  true, false, {"set_current_grid_editor"});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_C,         false, false, false, {Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   grid_editor_normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_P,         true,  false, false, {Action::PLOT_PLOTTER_LIST_ACTION_IDENTIFIER});
}




std::vector<std::string> AppController::find_grid_editor_action_mapping(UIGridEditor::mode_t mode, UIGridEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift, bool ctrl, bool alt)
{
   if (mode == UIGridEditor::NORMAL_MODE)
   {
      if (edit_mode_target == UIGridEditor::edit_mode_target_t::MEASURE_TARGET)
      {
         std::vector<std::string> found_mapping = grid_editor_normal_mode_measure_keyboard_mappings.get_mapping(al_keycode, shift, ctrl, alt);
         if (!found_mapping.empty()) return found_mapping;
      }
      else if (edit_mode_target == UIGridEditor::edit_mode_target_t::NOTE_TARGET)
      {
         std::vector<std::string> found_mapping = grid_editor_normal_mode_note_keyboard_mappings.get_mapping(al_keycode, shift, ctrl, alt);
         if (!found_mapping.empty()) return found_mapping;
      }

      std::vector<std::string> found_mapping = grid_editor_normal_mode_keyboard_mappings.get_mapping(al_keycode, shift, ctrl, alt);
      if (!found_mapping.empty()) return found_mapping;
   }

   return {};
}




void AppController::key_char_func()
{
   UIScreen::key_char_func();

   auto mode          = current_grid_editor_widget ? current_grid_editor_widget->mode : UIGridEditor::mode_t::NONE;
   auto target        = current_grid_editor_widget ? current_grid_editor_widget->edit_mode_target : UIGridEditor::edit_mode_target_t::NONE_TARGET;
   auto keycode       = Framework::current_event->keyboard.keycode;
   auto shift_pressed = Framework::key_shift;
   auto alt_pressed   = Framework::key_alt;
   auto ctrl_pressed  = Framework::key_ctrl;

   std::vector<std::string> identifiers;

   if (plotter_list_widget && plotter_list_widget->is_focused())
      identifiers = plotter_list_widget->get_keyboard_action_mapping(keycode, shift_pressed, ctrl_pressed, alt_pressed);
   else if (current_grid_editor_widget && current_grid_editor_widget->is_focused())
      identifiers = find_grid_editor_action_mapping(mode, target, keycode, shift_pressed, ctrl_pressed, alt_pressed);

   for (auto &identifier : identifiers)
   {
      Action::Base *action = nullptr;

      if (plotter_list_widget && plotter_list_widget->is_focused())
         action = UI::PlotterList::ActionFactory::create_action(plotter_list_widget, identifier);
      else if (current_grid_editor_widget && current_grid_editor_widget->is_focused())
         action = ActionFactory::create_action(this, identifier);

      if (action)
      {
         try
         {
            if (!action->execute()) throw std::runtime_error("Generic could-not-execute-action exception");
         }
         catch (const std::runtime_error& e)
         {
            std::cout << "Exception caught while trying to run action "
                      << "\"" << action->get_action_name() << "\""
                      << " with the following message \""
                      << e.what()
                      << "\""
                      << std::endl;
         }
         delete action;
      }
      else
      {
         std::stringstream error_message;
         error_message << "Action could not be found with the identifier \"" << identifier << "\". It should be creatable in the ActionFactory." << std::endl;
         throw std::runtime_error(error_message.str());
      }
   }
}




UIGridEditor *AppController::create_new_grid_editor(std::string name)
{
   static int new_x = 0;
   static int new_y = 0;

   UIGridEditor *new_grid_editor = new UIGridEditor(&follow_camera);
   new_grid_editor->grid = GridFactory::create(name);

   new_grid_editor->place.position = vec2d(new_x, new_y);
   new_grid_editor->place.align = vec2d(0.0, 0.0);

   grid_editors.push_back(new_grid_editor);

   new_y += 300;

   return new_grid_editor;
}




//bool AppController::set_current_grid_editor(UIGridEditor *editor)
//{
   //if (std::find(grid_editors.begin(), grid_editors.end(), editor) == grid_editors.end()) return false;

   //for (auto &e : grid_editors)
      //e->set_state(e == editor ? UIGridEditor::STATE_ACTIVE : UIGridEditor::STATE_INACTIVE);

   //current_grid_editor = editor;

   //// move the camera to the new current_grid_editor
   //follow_camera.target.position = -current_grid_editor->place.position + vec2d(200, 200);

   //return true;
//}


bool AppController::set_current_grid_editor_widget(UIGridEditor *editor)
{
   if (std::find(grid_editors.begin(), grid_editors.end(), editor) == grid_editors.end()) return false;

   for (auto &e : grid_editors)
      e->set_state(e == editor ? UIGridEditor::STATE_ACTIVE : UIGridEditor::STATE_INACTIVE);

   current_grid_editor_widget = editor;

   // move the camera to the new current_grid_editor_widget
   follow_camera.target.position = -current_grid_editor_widget->place.position + vec2d(200, 200);

   return true;
}




UIGridEditor *AppController::get_next_grid_editor()
{
   if (!current_grid_editor_widget || grid_editors.size() <= 1) return nullptr;

   std::vector<UIGridEditor *>::iterator it = std::find(grid_editors.begin(), grid_editors.end(), current_grid_editor_widget);

   if (it == grid_editors.end()) return nullptr; // does not exist in list
   if (it == grid_editors.end()-1) return grid_editors.front(); // loop back to first element
   ++it;
   return *it;
}




