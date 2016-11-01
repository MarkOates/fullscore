



#include <fullscore/fullscore_application_controller.h>

#include <fullscore/actions/transforms/add_dot_transform_action.h>
#include <fullscore/actions/transforms/double_duration_transform_action.h>
#include <fullscore/actions/transforms/erase_note_action.h>
#include <fullscore/actions/transforms/half_duration_transform_action.h>
#include <fullscore/actions/transforms/insert_note_action.h>
#include <fullscore/actions/transforms/invert_action.h>
#include <fullscore/actions/transforms/remove_dot_transform_action.h>
#include <fullscore/actions/transforms/retrograde_action.h>
#include <fullscore/actions/transforms/toggle_rest_action.h>
#include <fullscore/actions/transforms/transpose_up_action.h>
#include <fullscore/actions/transforms/transpose_down_action.h>
#include <fullscore/actions/append_measure_action.h>
#include <fullscore/actions/append_staff_action.h>
#include <fullscore/actions/delete_measure_action.h>
#include <fullscore/actions/delete_staff_action.h>
#include <fullscore/actions/insert_measure_action.h>
#include <fullscore/actions/insert_staff_action.h>
#include <fullscore/actions/load_measure_grid_action.h>
#include <fullscore/actions/move_cursor_down_action.h>
#include <fullscore/actions/move_cursor_left_action.h>
#include <fullscore/actions/move_cursor_right_action.h>
#include <fullscore/actions/move_cursor_up_action.h>
#include <fullscore/actions/paste_measure_from_buffer_action.h>
#include <fullscore/actions/reset_playback_action.h>
#include <fullscore/actions/save_measure_grid_action.h>
#include <fullscore/actions/set_score_zoom_action.h>
#include <fullscore/actions/start_motion_action.h>
#include <fullscore/actions/toggle_edit_mode_target_action.h>
#include <fullscore/actions/toggle_help_window_action.h>
#include <fullscore/actions/toggle_playback_action.h>
#include <fullscore/actions/toggle_show_debug_data_action.h>
#include <fullscore/actions/set_command_mode_action.h>
#include <fullscore/actions/set_normal_mode_action.h>
#include <fullscore/actions/set_mode_action.h>
#include <fullscore/actions/yank_measure_to_buffer_action.h>





FullscoreApplicationController::FullscoreApplicationController(Display *display)
   : UIScreen(display)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , action_queue()
   , score_editor(NULL)
   , command_bar(NULL)
   , gui_mixer(NULL)
   , help_window(NULL)
   , yank_measure_buffer()
   , showing_help_menu(false)
{
   UIScreen::draw_focused_outline = false;

   score_editor = new GUIScoreEditor(this, display, new PlaybackDeviceGeneric());
   gui_mixer = new UIMixer(this, 1600, 1200);
   command_bar = new UICommandBar(this);

   simple_notification_screen->spawn_notification("Press F1 for help");

   create_help_window();

   Framework::motion().cmove(&score_editor->place.position.y, 200, 0.4);
   Framework::motion().cmove(&score_editor->place.position.x, 200, 0.4);
}




void FullscoreApplicationController::create_help_window()
{
   help_window = new UIFramedWindow(this, -600, -100, 550, 700);
   help_window->set_title("Help");

   UIText *help_title = new UIText(help_window, 25, 25, "Controls");
   UITextBox *help_paragraph = new UITextBox(help_window, 25, 25+70, 500, 500, php::file_get_contents("data/documents/help.txt"));

   help_paragraph->set_text_color(color::white);

   help_title->place.align = vec2d(0, 0);
   help_paragraph->place.align = vec2d(0, 0);
}




void FullscoreApplicationController::primary_timer_func()
{
   UIScreen::primary_timer_func();
   command_bar->set_time(score_editor->playback_control.position);
}




std::string FullscoreApplicationController::find_action_identifier_by_normal_mode_keycode(int al_keycode, bool shift, bool alt)
{
   switch(al_keycode)
   {
   case ALLEGRO_KEY_W: return "transpose_up"; break;
   case ALLEGRO_KEY_S: return "transpose_down"; break;
   case ALLEGRO_KEY_A: return "half_duration"; break;
   case ALLEGRO_KEY_D: return "double_duration"; break;
   case ALLEGRO_KEY_R: return "toggle_rest"; break;
   case ALLEGRO_KEY_I: return "invert"; break;
   case ALLEGRO_KEY_FULLSTOP: return "add_dot"; break;
   case ALLEGRO_KEY_COMMA: return "remove_dot"; break;
   case ALLEGRO_KEY_SEMICOLON: return "set_command_mode"; break;
   case ALLEGRO_KEY_E: return "erase_note"; break;
   case ALLEGRO_KEY_G: return "retrograde"; break;
   case ALLEGRO_KEY_N: return "insert_note"; break;
   case ALLEGRO_KEY_F1: return "toggle_help_window"; break;
   case ALLEGRO_KEY_F2: return "toggle_show_debug_data"; break;
   case ALLEGRO_KEY_SPACE: return "toggle_playback"; break;
   case ALLEGRO_KEY_Q: return "reset_playback"; break;
   case ALLEGRO_KEY_F7: return "save_measure_grid"; break;
   case ALLEGRO_KEY_F8: return "load_measure_grid"; break;
   case ALLEGRO_KEY_UP: return "move_camera_up"; break;
   case ALLEGRO_KEY_DOWN: return "move_camera_down"; break;
   case ALLEGRO_KEY_RIGHT: return "move_camera_right"; break;
   case ALLEGRO_KEY_LEFT: return "move_camera_left"; break;
   case ALLEGRO_KEY_EQUALS: return shift ? "camera_zoom_default" : "camera_zoom_in"; break;
   case ALLEGRO_KEY_MINUS: return "camera_zoom_out"; break;
   case ALLEGRO_KEY_H: return "move_cursor_left"; break;
   case ALLEGRO_KEY_J: return "move_cursor_down"; break;
   case ALLEGRO_KEY_K: return "move_cursor_up"; break;
   case ALLEGRO_KEY_L: return "move_cursor_right"; break;
   case ALLEGRO_KEY_Y: return "yank_measure_to_buffer"; break;
   case ALLEGRO_KEY_P: return "paste_measure_from_buffer"; break;
   case ALLEGRO_KEY_TAB: return "toggle_edit_mode_target"; break;
   }

   return "";
}




std::string FullscoreApplicationController::find_action_identifier_by_command_mode_keycode(int al_keycode, bool shift, bool alt)
{
   switch(al_keycode)
   {
   case ALLEGRO_KEY_SEMICOLON: return "set_normal_mode"; break;
   }

   return "";
}




std::string FullscoreApplicationController::find_action_identifier_by_edit_mode_keycode(int al_keycode, bool shift, bool alt)
{
   // no implementation
   return "";
}




void FullscoreApplicationController::execute_command_mode_action_for_key(int al_keycode)
{
   switch(al_keycode)
   {
   case ALLEGRO_KEY_SEMICOLON:
      {
         Action::SetNormalMode set_mode_action(score_editor, command_bar);
         set_mode_action.execute();
      }
      break;
   default:
      break;
   }
}




void FullscoreApplicationController::execute_edit_mode_action_for_key(int al_keycode)
{
   // no implementation
}




Action::Base *FullscoreApplicationController::create_action(std::string action_name)
{
   //
   // SCORE EDITING COMMANDS
   //

   Action::Base *action = nullptr;
   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   Measure *focused_measure = nullptr;

   if (score_editor->is_note_target_mode())
   {
      single_note = score_editor->get_note_at_cursor();
   }
   if (score_editor->is_measure_target_mode())
   {
      focused_measure = score_editor->get_measure_at_cursor();
      if (focused_measure) notes = &focused_measure->notes;
   }

   if (action_name == "transpose_up")
      action = new Action::TransposeUp(single_note);
   else if (action_name == "transpose_down")
      action = new Action::TransposeDown(single_note);
   else if (action_name == "half_duration")
      action = new Action::HalfDurationTransform(single_note);
   else if (action_name == "double_duration")
      action = new Action::DoubleDurationTransform(single_note);
   else if (action_name == "toggle_rest")
      action = new Action::ToggleRest(single_note);
   else if (action_name == "invert")
      action = new Action::Transform::Invert(single_note, 0);
   else if (action_name == "add_dot")
      action = new Action::AddDotTransform(single_note);
   else if (action_name == "remove_dot")
      action = new Action::RemoveDotTransform(single_note);
   else if (action_name == "set_command_mode")
      action = new Action::SetCommandMode(score_editor, command_bar);
   else if (action_name == "set_normal_mode")
      action = new Action::SetNormalMode(score_editor, command_bar);
   else if (action_name == "erase_note")
      action = new Action::EraseNote(notes, score_editor->note_cursor_x);
   else if (action_name == "retrograde")
      action = new Action::Transform::Retrograde(notes);
   else if (action_name == "insert_note")
      action = new Action::InsertNoteTransform(notes, score_editor->note_cursor_x, Note());
   else if (action_name == "toggle_help_window")
      action = new Action::ToggleHelpWindow(&Framework::motion(), this);
   else if (action_name == "toggle_show_debug_data")
      action = new Action::ToggleShowDebugData(score_editor);
   else if (action_name == "toggle_playback")
      action = new Action::TogglePlayback(score_editor, gui_mixer);
   else if (action_name == "reset_playback")
      action = new Action::ResetPlayback(score_editor);
   else if (action_name == "save_measure_grid")
      action = new Action::SaveMeasureGrid(&score_editor->measure_grid, "score_filename.fs");
   else if (action_name == "load_measure_grid")
      action = new Action::LoadMeasureGrid(&score_editor->measure_grid, "score_filename.fs");
   else if (action_name == "move_camera_up")
      action = new Action::StartMotion(&Framework::motion(), &score_editor->place.position.y, score_editor->place.position.y+200, 0.4);
   else if (action_name == "move_camera_down")
      action = new Action::StartMotion(&Framework::motion(), &score_editor->place.position.y, score_editor->place.position.y-200, 0.4);
   else if (action_name == "move_camera_right")
      action = new Action::StartMotion(&Framework::motion(), &score_editor->place.position.x, score_editor->place.position.x-200, 0.4);
   else if (action_name == "move_camera_left")
      action = new Action::StartMotion(&Framework::motion(), &score_editor->place.position.x, score_editor->place.position.x+200, 0.4);
   else if (action_name == "camera_zoom_in")
      action = new Action::SetScoreZoom(score_editor, &Framework::motion(), score_editor->place.scale.x + 0.1, 0.3);
   else if (action_name == "camera_zoom_default")
      action = new Action::SetScoreZoom(score_editor, &Framework::motion(), 1, 0.3);
   else if (action_name == "camera_zoom_out")
      action = new Action::SetScoreZoom(score_editor, &Framework::motion(), score_editor->place.scale.x - 0.1, 0.3);
   else if (action_name == "move_cursor_left")
      action = new Action::MoveCursorLeft(score_editor);
   else if (action_name == "move_cursor_down")
      action = new Action::MoveCursorDown(score_editor);
   else if (action_name == "move_cursor_up")
      action = new Action::MoveCursorUp(score_editor);
   else if (action_name == "move_cursor_right")
      action = new Action::MoveCursorRight(score_editor);
   else if (action_name == "yank_measure_to_buffer")
      action = new Action::YankMeasureToBuffer(&yank_measure_buffer, focused_measure);
   else if (action_name == "paste_measure_from_buffer")
      action = new Action::PasteMeasureFromBuffer(focused_measure, &yank_measure_buffer);
   else if (action_name == "toggle_edit_mode_target")
      action = new Action::ToggleEditModeTarget(score_editor);
   else if (action_name == "insert_measure")
      action = new Action::InsertMeasure(&score_editor->measure_grid, score_editor->measure_cursor_x);
   else if (action_name == "delete_measure")
      action = new Action::DeleteMeasure(&score_editor->measure_grid, score_editor->measure_cursor_x);
   else if (action_name == "insert_staff")
      action = new Action::InsertStaff(&score_editor->measure_grid, score_editor->measure_cursor_y);
   else if (action_name == "delete_staff")
      action = new Action::DeleteStaff(&score_editor->measure_grid, score_editor->measure_cursor_y);
   else if (action_name == "append_measure")
      action = new Action::AppendMeasure(&score_editor->measure_grid);
   else if (action_name == "append_staff")
      action = new Action::AppendStaff(&score_editor->measure_grid);

   return action;
}




void FullscoreApplicationController::key_down_func()
{
   UIScreen::key_down_func();

   int key = Framework::current_event->keyboard.keycode;

   switch(score_editor->mode)
   {
   case GUIScoreEditor::NORMAL_MODE:
      {
         std::string identifier = find_action_identifier_by_normal_mode_keycode(key, Framework::key_shift, Framework::key_alt);

         Action::Base *action = create_action(identifier);

         if (action)
         {
            action->execute();
            delete action;
         }
      }
      break;
   case GUIScoreEditor::INSERT_MODE:
      {
         std::string identifier = find_action_identifier_by_edit_mode_keycode(key, Framework::key_shift, Framework::key_alt);

         Action::Base *action = create_action(identifier);

         if (action)
         {
            action->execute();
            delete action;
         }
      }
      break;
   case GUIScoreEditor::COMMAND_MODE:
      {
         std::string identifier = find_action_identifier_by_command_mode_keycode(key, Framework::key_shift, Framework::key_alt);

         Action::Base *action = create_action(identifier);

         if (action)
         {
            action->execute();
            delete action;
         }
      }
      break;
   }
}




void FullscoreApplicationController::on_message(UIWidget *sender, std::string message)
{
   std::cout << "message: " << message << std::endl;

   if (sender == command_bar && message != "on_submit")
   {
      if (!message.empty() && message[0] == ':')
      {
         std::string action_identifier = message.substr(1);

         Action::Base *action = create_action(action_identifier);

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

            Action::SetNormalMode return_to_normal_mode(score_editor, command_bar);
            return_to_normal_mode.execute();
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

         Action::SetNormalMode return_to_normal_mode(score_editor, command_bar);
         return_to_normal_mode.execute();
      }
   }
}




