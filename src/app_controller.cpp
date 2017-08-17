



#include <fullscore/app_controller.h>

#include <fullscore/factories/action_factory.h>
#include <fullscore/factories/grid_factory.h>
#include <fullscore/models/measure.h>



AppController::AppController(Display *display)
   : UIScreen(display)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , action_queue("master_queue")
   , follow_camera(this)
   , current_grid_editor(nullptr)
   , grid_editors()
   , command_bar(new UICommandBar(this))
   , ui_measure_inspector(new UIMeasureInspector(this))
   , yank_measure_buffer()
   , reference_cursor(nullptr, 0, 0)
{
   UIScreen::draw_focused_outline = false;

   set_current_grid_editor(create_new_grid_editor("full_score"));
}




void AppController::primary_timer_func()
{
   if (ui_measure_inspector) ui_measure_inspector->set_measure(current_grid_editor->get_measure_at_cursor());
   ui_measure_inspector->place.position = vec2d(display->width(), 0);
   ui_measure_inspector->place.size = vec2d(300, display->height());

   UIScreen::primary_timer_func();
}




std::string AppController::find_action_identifier(UIGridEditor::mode_t mode, UIGridEditor::edit_mode_target_t edit_mode_target, int al_keycode, bool shift, bool ctrl, bool alt)
{
   switch(al_keycode)
   {
      case ALLEGRO_KEY_N: if(ctrl) return "create_new_grid_editor"; break;
      case ALLEGRO_KEY_X: if(ctrl) return "set_current_grid_editor"; break;
      case ALLEGRO_KEY_UP: return "move_camera_up"; break;
      case ALLEGRO_KEY_DOWN: return "move_camera_down"; break;
      case ALLEGRO_KEY_RIGHT: return "move_camera_right"; break;
      case ALLEGRO_KEY_LEFT: return "move_camera_left"; break;
   }

   if (mode == UIGridEditor::NORMAL_MODE)
      switch(al_keycode)
      {
      case ALLEGRO_KEY_F:
         if (ctrl && edit_mode_target == UIGridEditor::edit_mode_target_t::MEASURE_TARGET) { return "ascend"; }
         return "transpose_up";
         break;
      case ALLEGRO_KEY_D:
         if (ctrl && edit_mode_target == UIGridEditor::edit_mode_target_t::MEASURE_TARGET) { return "descend"; }
         return "transpose_down";
         break;
      case ALLEGRO_KEY_S: if (shift) { return "split_note"; }; return "half_duration"; break;
      case ALLEGRO_KEY_G: return "double_duration"; break;
      case ALLEGRO_KEY_7: if (shift) { return "set_reference_by_id_measure"; } break;
      case ALLEGRO_KEY_8: if (shift) { return "set_reference_by_coordinate_measure"; } break;
      case ALLEGRO_KEY_R: return "toggle_rest"; break;
      case ALLEGRO_KEY_C: if (shift) return "set_reference_cursor"; break;
      case ALLEGRO_KEY_N: return "invert"; break;
      case ALLEGRO_KEY_FULLSTOP: return "add_dot_to_note"; break;
      case ALLEGRO_KEY_COMMA: return "remove_dot"; break;
      case ALLEGRO_KEY_SEMICOLON: return "set_command_mode"; break;
      case ALLEGRO_KEY_X:
         if (edit_mode_target == UIGridEditor::edit_mode_target_t::NOTE_TARGET) { return "erase_note"; }
         else if (edit_mode_target == UIGridEditor::edit_mode_target_t::MEASURE_TARGET) { return "delete_measure"; }
         break;
      case ALLEGRO_KEY_Z: return "retrograde"; break;
      case ALLEGRO_KEY_A:
         if (edit_mode_target == UIGridEditor::edit_mode_target_t::NOTE_TARGET) { return "insert_note_after"; }
         break;
      case ALLEGRO_KEY_I:
         if (edit_mode_target == UIGridEditor::edit_mode_target_t::NOTE_TARGET) { return "insert_note"; }
         break;
      case ALLEGRO_KEY_F2: return "toggle_show_debug_data"; break;
      case ALLEGRO_KEY_SPACE: return "toggle_playback"; break;
      case ALLEGRO_KEY_Q: return "reset_playback"; break;
      case ALLEGRO_KEY_F7: return "save_grid"; break;
      case ALLEGRO_KEY_F8: return "load_grid"; break;
      case ALLEGRO_KEY_EQUALS: return shift ? "camera_zoom_default" : "camera_zoom_in"; break;
      case ALLEGRO_KEY_MINUS: return "camera_zoom_out"; break;
      case ALLEGRO_KEY_H: return "move_cursor_left"; break;
      case ALLEGRO_KEY_J: return "move_cursor_down"; break;
      case ALLEGRO_KEY_K: return "move_cursor_up"; break;
      case ALLEGRO_KEY_L: return "move_cursor_right"; break;
      case ALLEGRO_KEY_M: if(shift) return "set_basic_measure"; break;
      case ALLEGRO_KEY_Y: return "yank_measure_to_buffer"; break;
      case ALLEGRO_KEY_P: return "paste_measure_from_buffer"; break;
      case ALLEGRO_KEY_O: return "octatonic_1"; break;
      case ALLEGRO_KEY_TAB: return "toggle_edit_mode_target"; break;
      case ALLEGRO_KEY_2: return "set_time_signature_numerator_2"; break;
      case ALLEGRO_KEY_3: if (shift) { return "set_stack_measure"; }; return "set_time_signature_numerator_3"; break;
      case ALLEGRO_KEY_4: return "set_time_signature_numerator_4"; break;
      case ALLEGRO_KEY_5: return "set_time_signature_numerator_5"; break;
      }

   if (mode == UIGridEditor::COMMAND_MODE)
      switch(al_keycode)
      {
      case ALLEGRO_KEY_SEMICOLON: return "set_normal_mode"; break;
      }

   if (mode == UIGridEditor::INSERT_MODE)
      // no implementation
      ;

   return "";
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

   std::string identifier = find_action_identifier(mode, target, keycode, shift_pressed, ctrl_pressed, alt_pressed);
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
}




void AppController::on_message(UIWidget *sender, std::string message)
{
   std::cout << "message: " << message << std::endl;

   if (sender == command_bar && message != "on_submit")
   {
      if (!message.empty())
      {
         std::string action_identifier = message;

         Action::Base *action = ActionFactory::create_action(this, action_identifier);

         if (action)
         {
            std::string success_message = action->get_action_name();

            if (success_message != action_identifier)
            {
               success_message = "Calling non-atomic action: ";
               success_message += message + " using " + action->get_action_name();
            }

            simple_notification_screen->spawn_notification(success_message);
            action->execute();
            delete action;

            Action::Base *set_normal_mode_action = ActionFactory::create_action(this, "set_normal_mode");
            if (!set_normal_mode_action) throw std::runtime_error("Cannot return to NORMAL_MODE; \"set_normal_mode\" action not found");
            set_normal_mode_action->execute();
            delete set_normal_mode_action;
         }
         else
         {
            std::string error_message = "Unfound action: ";
            error_message += action_identifier;
            simple_notification_screen->spawn_notification(error_message);
         }
      }
      else
      {
         std::string error_message = "Unrecognized input: ";
         error_message += message;
         simple_notification_screen->spawn_notification(error_message);

         Action::Base *set_normal_mode_action = ActionFactory::create_action(this, "set_normal_mode");
         if (!set_normal_mode_action) throw std::runtime_error("Cannot return to NORMAL_MODE; \"set_normal_mode\" action not found");
         set_normal_mode_action->execute();
         delete set_normal_mode_action;
      }
   }
}




UIGridEditor *AppController::create_new_grid_editor(std::string name)
{
   static int new_x = 0;
   static int new_y = 0;

   UIGridEditor *new_grid_editor = new UIGridEditor(&follow_camera, &reference_cursor);
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




