



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
#include <fullscore/actions/transforms/transpose_transform_action.h>
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
#include <fullscore/actions/set_mode_action.h>
#include <fullscore/actions/yank_measure_to_buffer_action.h>





FullscoreApplicationController::FullscoreApplicationController(Display *display)
   : UIScreen(display)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
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




void FullscoreApplicationController::execute_normal_mode_action_for_key(int al_keycode)
{
   //
   // SCORE EDITING COMMANDS
   //

   Action::Base *action = nullptr;

   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   std::vector<Note> single_note_as_array;

   if (score_editor->is_measure_target_mode())
   {
      Measure *focused_measure = score_editor->get_measure_at_cursor();
      if (focused_measure) notes = &focused_measure->notes;
   }
   else
   {
      single_note = score_editor->get_note_at_cursor();
      if (single_note)
      {
         single_note_as_array.push_back(*single_note);
         notes = &single_note_as_array;
      }
   }

   // locate and build the appropriate transform
   switch(al_keycode)
   {
   case ALLEGRO_KEY_SEMICOLON:
      {
         action = new Action::SetMode(score_editor, command_bar, GUIScoreEditor::COMMAND_MODE);
      }
      break;
   case ALLEGRO_KEY_W:
      {
         action = new Action::TransposeTransform(notes, Framework::key_shift ? 7 : 1);
      }
      break;
   case ALLEGRO_KEY_S:
      {
         action = new Action::TransposeTransform(notes, Framework::key_shift ? -7 : -1);
      }
      break;
   case ALLEGRO_KEY_A:
      {
         action = new Action::HalfDurationTransform(notes);
      }
      break;
   case ALLEGRO_KEY_D:
      {
         action = new Action::DoubleDurationTransform(notes);
      }
      break;
   case ALLEGRO_KEY_R:
      {
         action = new Action::ToggleRest(notes);
      }
      break;
   case ALLEGRO_KEY_E:
      {
         action = new Action::EraseNote(notes, score_editor->note_cursor_x);
      }
      break;
   case ALLEGRO_KEY_I:
      {
         action = new Action::Transform::Invert(0);
      }
      break;
   case ALLEGRO_KEY_G:
      {
         action = new Action::Transform::Retrograde(notes);
      }
      break;
   case ALLEGRO_KEY_FULLSTOP:
      {
         action = new Action::AddDotTransform(notes);
      }
      break;
   case ALLEGRO_KEY_COMMA:
      {
         action = new Action::RemoveDotTransform(notes);
      }
      break;
   case ALLEGRO_KEY_N:
      {
         action = new Action::InsertNoteTransform(notes, score_editor->note_cursor_x, Note());
      }
      break;
   case ALLEGRO_KEY_F1:
      {
         action = new Action::ToggleHelpWindow(&Framework::motion(), this);
      }
      break;
   case ALLEGRO_KEY_F2:
      {
         action = new Action::ToggleShowDebugData(score_editor);
      }
      break;
   case ALLEGRO_KEY_SPACE:
      {
         action = new Action::TogglePlayback(score_editor, gui_mixer);
      }
      break;
   case ALLEGRO_KEY_Q:
      {
         action = new Action::ResetPlayback(score_editor);
      }
      break;
   case ALLEGRO_KEY_F7:
      {
         action = new Action::SaveMeasureGrid(&score_editor->measure_grid, "score_filename.fs");
      }
      break;
   case ALLEGRO_KEY_F8:
      {
         action = new Action::LoadMeasureGrid(&score_editor->measure_grid, "score_filename.fs");
      }
      break;
   case ALLEGRO_KEY_UP:
      {
         action = new Action::StartMotion(&Framework::motion(),
            &score_editor->place.position.y, score_editor->place.position.y+200, 0.4);
      }
      break;
   case ALLEGRO_KEY_DOWN:
      {
         action = new Action::StartMotion(&Framework::motion(),
            &score_editor->place.position.y, score_editor->place.position.y-200, 0.4);
      }
      break;
   case ALLEGRO_KEY_RIGHT:
      {
         action = new Action::StartMotion(&Framework::motion(),
            &score_editor->place.position.x, score_editor->place.position.x-200, 0.4);
      }
      break;
   case ALLEGRO_KEY_LEFT:
      {
         action = new Action::StartMotion(&Framework::motion(),
            &score_editor->place.position.x, score_editor->place.position.x+200, 0.4);
      }
      break;
   case ALLEGRO_KEY_EQUALS:
      {
         if (Framework::key_shift)
         {
            action = new Action::SetScoreZoom(score_editor, &Framework::motion(), 1, 0.3);
         }
         else
         {
            action = new Action::SetScoreZoom(score_editor, &Framework::motion(), score_editor->place.scale.x + 0.1, 0.3);
         }
      }
      break;
   case ALLEGRO_KEY_MINUS:
      {
         action = new Action::SetScoreZoom(score_editor, &Framework::motion(), score_editor->place.scale.x - 0.1, 0.3);
      }
      break;
   case ALLEGRO_KEY_H:
      {
         action = new Action::MoveCursorLeft(score_editor);
      }
      break;
   case ALLEGRO_KEY_J:
      {
         action = new Action::MoveCursorDown(score_editor);
      }
      break;
   case ALLEGRO_KEY_K:
      {
         action = new Action::MoveCursorUp(score_editor);
      }
      break;
   case ALLEGRO_KEY_L:
      {
         action = new Action::MoveCursorRight(score_editor);
      }
      break;
   case ALLEGRO_KEY_Y:
      {
         Measure *focused_measure = score_editor->get_measure_at_cursor();
         action = new Action::YankMeasureToBuffer(&yank_measure_buffer, focused_measure);
      }
      break;
   case ALLEGRO_KEY_P:
      {
         Measure *destination_measure = score_editor->get_measure_at_cursor();
         action = new Action::PasteMeasureFromBuffer(destination_measure, &yank_measure_buffer);
      }
      break;
   case ALLEGRO_KEY_TAB:
      {
         action = new Action::ToggleEditModeTarget(score_editor);
      }
      break;
   }

   if (action)
   {
      action->execute();
      delete action;
   }

   if (single_note && !single_note_as_array.empty())
   {
      *single_note = single_note_as_array.at(0);
   }
}




void FullscoreApplicationController::execute_command_mode_action_for_key(int al_keycode)
{
   switch(al_keycode)
   {
   case ALLEGRO_KEY_SEMICOLON:
      {
         Action::SetMode set_mode_action(score_editor, command_bar, GUIScoreEditor::NORMAL_MODE);
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




void FullscoreApplicationController::key_down_func()
{
   UIScreen::key_down_func();

   int key = Framework::current_event->keyboard.keycode;

   switch(score_editor->mode)
   {
   case GUIScoreEditor::NORMAL_MODE:
      execute_normal_mode_action_for_key(key);
      break;
   case GUIScoreEditor::INSERT_MODE:
      execute_edit_mode_action_for_key(key);
      break;
   case GUIScoreEditor::COMMAND_MODE:
      execute_command_mode_action_for_key(key);
      break;
   }
}




void FullscoreApplicationController::on_message(UIWidget *sender, std::string message)
{
   std::cout << "message: " << message << std::endl;

   if (message == "insert_measure")
   {
      Action::InsertMeasure insert_measure_action(&score_editor->measure_grid, score_editor->measure_cursor_x);
      insert_measure_action.execute();
   }
   if (message == "delete_measure")
   {
      Action::DeleteMeasure delete_measure_action(&score_editor->measure_grid, score_editor->measure_cursor_x);
      delete_measure_action.execute();
   }
   if (message == "insert_staff")
   {
      Action::InsertStaff insert_staff_action(&score_editor->measure_grid, score_editor->measure_cursor_y);
      insert_staff_action.execute();
   }
   if (message == "delete_staff")
   {
      Action::DeleteStaff delete_staff_action(&score_editor->measure_grid, score_editor->measure_cursor_y);
      delete_staff_action.execute();
   }
   if (message == "append_measure")
   {
      Action::AppendMeasure append_measure_action(&score_editor->measure_grid);
      append_measure_action.execute();
   }
   if (message == "append_staff")
   {
      Action::AppendStaff append_staff_action(&score_editor->measure_grid);
      append_staff_action.execute();
   }
}




