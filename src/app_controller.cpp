


#include <fullscore/app_controller.h>

#include <allegro_flare/framework.h>
#include <fullscore/factories/action_factory.h>
#include <fullscore/factories/grid_factory.h>
#include <fullscore/models/floating_measure.h>
#include <fullscore/models/grid_coordinate.h>
#include <fullscore/models/measure.h>
#include <fullscore/models/staff.h>
#include <fullscore/action.h>



AppController::AppController(Display *display, Config &config)
   : UIScreen(display)
   , config(config)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , action_queue("master_queue")
   , follow_camera(this)
   , current_grid_editor(nullptr)
   , grid_editors()
   //, command_bar(new UICommandBar(this))
   //, ui_measure_inspector(new UIMeasureInspector(this))
   , yank_measure_buffer()
   , normal_mode_keyboard_mappings()
   , normal_mode_note_keyboard_mappings()
   , normal_mode_measure_keyboard_mappings()
{
   UIScreen::draw_focused_outline = false;

   std::string init_template_identifier = config.get_or_default_str("FULLSCORE_SETTINGS", "init_template", "string_quartet");
   set_current_grid_editor(create_new_grid_editor(init_template_identifier));

   set_keyboard_input_mappings();
}



void AppController::set_keyboard_input_mappings()
{
   //                                        keycode,               shift, ctrl,  alt,   identifier
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_G,         false, false, false, {"double_duration"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_R,         false, false, false, {"toggle_rest"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_N,         false, false, false, {"invert"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_Z,         false, false, false, {"retrograde"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_H,         false, false, false, {Action::MOVE_CURSOR_LEFT_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_J,         false, false, false, {Action::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_SEMICOLON, false, false, false, {"set_command_mode"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_MINUS,     false, false, false, {"camera_zoom_out"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_EQUALS,    false, false, false, {"camera_zoom_in"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_UP,        false, false, false, {"move_camera_up"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_DOWN,      false, false, false, {"move_camera_down"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_RIGHT,     false, false, false, {"move_camera_right"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_LEFT,      false, false, false, {"move_camera_left"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_TAB,       false, false, false, {"toggle_edit_mode_target"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F2,        false, false, false, {"toggle_show_debug_data"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_SPACE,     false, false, false, {"toggle_playback"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_Q,         false, false, false, {"reset_playback"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F7,        false, false, false, {"save_grid"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F8,        false, false, false, {"load_grid"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_4,         false, false, false, {"set_time_signature_numerator_4"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_5,         false, false, false, {"set_time_signature_numerator_5"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_Y,         false, false, false, {Action::YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_P,         false, false, false, {Action::PASTE_MEASURE_FROM_BUFFER_ACTION_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_O,         false, false, false, {"octatonic_1"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_2,         false, false, false, {"set_time_signature_numerator_2"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_K,         false, false, false, {Action::MOVE_CURSOR_UP_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_L,         false, false, false, {Action::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_W,         false, false, false, {Action::MOVE_FLOATING_MEASURE_CURSOR_RIGHT_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_B,         true,  false, false, {Action::MOVE_FLOATING_MEASURE_CURSOR_LEFT_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_S,         false, false, false, {"half_duration"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_3,         false, false, false, {"set_time_signature_numerator_3"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_F,         false, false, false, {"transpose_up"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_D,         false, false, false, {"transpose_down"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_S,         false,  true, false, {"split_note"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_7,         true,  false, false, {"set_reference_by_id_measure"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_EQUALS,    true,  false, false, {"camera_zoom_default"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_M,         false, false, false, {Action::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER
                                                                                         ,Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_3,         true,  false, false, {"set_stack_measure"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_N,         false,  true, false, {"create_new_grid_editor"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_X,         false,  true, false, {"set_current_grid_editor"});
   normal_mode_keyboard_mappings.set_mapping(ALLEGRO_KEY_C,         false, false, false, {Action::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});



   // measure mode commands
   normal_mode_measure_keyboard_mappings.set_mapping(ALLEGRO_KEY_F, false, true,  false, {"ascend"});
   normal_mode_measure_keyboard_mappings.set_mapping(ALLEGRO_KEY_D, false, true,  false, {"descend"});
   normal_mode_measure_keyboard_mappings.set_mapping(ALLEGRO_KEY_X, false, false, false, {Action::DELETE_FLOATING_MEASURE_IDENTIFIER});



   // note mode commands
   normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_A,        false, false, false, {"insert_note_after"});
   normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_X,        false, false, false, {"erase_note"});
   normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_I,        false, false, false, {"insert_note"});
   normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_COMMA,    false, false, false, {"remove_dot"});
   normal_mode_note_keyboard_mappings.set_mapping(ALLEGRO_KEY_FULLSTOP, false, false, false, {"add_dot_to_note"});
}




std::vector<std::string> AppController::find_action_mapping(UIGridEditor::mode_t mode, UIGridEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift, bool ctrl, bool alt)
{
   if (mode == UIGridEditor::NORMAL_MODE)
   {
      if (edit_mode_target == UIGridEditor::edit_mode_target_t::MEASURE_TARGET)
      {
         std::vector<std::string> found_mapping = normal_mode_measure_keyboard_mappings.get_mapping(al_keycode, shift, ctrl, alt);
         if (!found_mapping.empty()) return found_mapping;
      }
      else if (edit_mode_target == UIGridEditor::edit_mode_target_t::NOTE_TARGET)
      {
         std::vector<std::string> found_mapping = normal_mode_note_keyboard_mappings.get_mapping(al_keycode, shift, ctrl, alt);
         if (!found_mapping.empty()) return found_mapping;
      }

      std::vector<std::string> found_mapping = normal_mode_keyboard_mappings.get_mapping(al_keycode, shift, ctrl, alt);
      if (!found_mapping.empty()) return found_mapping;
   }

   return {};
}




void AppController::key_char_func()
{
   UIScreen::key_char_func();

   auto mode          = current_grid_editor ? current_grid_editor->mode : UIGridEditor::mode_t::NONE;
   auto target        = current_grid_editor ? current_grid_editor->edit_mode_target : UIGridEditor::edit_mode_target_t::NONE_TARGET;
   auto keycode       = Framework::current_event->keyboard.keycode;
   auto shift_pressed = Framework::key_shift;
   auto alt_pressed   = Framework::key_alt;
   auto ctrl_pressed  = Framework::key_ctrl;

   std::vector<std::string> identifiers = find_action_mapping(mode, target, keycode, shift_pressed, ctrl_pressed, alt_pressed);

   for (auto &identifier : identifiers)
   {
      Action::Base *action = ActionFactory::create_action(this, identifier);

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
         error_message << "Action could not be found with the identifier \"" << identifier << "\"" << std::endl;
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




bool AppController::set_current_grid_editor(UIGridEditor *editor)
{
   if (std::find(grid_editors.begin(), grid_editors.end(), editor) == grid_editors.end()) return false;

   for (auto &e : grid_editors)
      e->set_state(e == editor ? UIGridEditor::STATE_ACTIVE : UIGridEditor::STATE_INACTIVE);

   current_grid_editor = editor;

   // move the camera to the new current_grid_editor
   follow_camera.target.position = -current_grid_editor->place.position + vec2d(200, 200);

   return true;
}




UIGridEditor *AppController::get_next_grid_editor()
{
   if (!current_grid_editor || grid_editors.size() <= 1) return nullptr;

   std::vector<UIGridEditor *>::iterator it = std::find(grid_editors.begin(), grid_editors.end(), current_grid_editor);

   if (it == grid_editors.end()) return nullptr; // does not exist in list
   if (it == grid_editors.end()-1) return grid_editors.front(); // loop back to first element
   ++it;
   return *it;
}




