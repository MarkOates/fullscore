



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
#include <fullscore/actions/move_cursor_down_action.h>
#include <fullscore/actions/move_cursor_left_action.h>
#include <fullscore/actions/move_cursor_right_action.h>
#include <fullscore/actions/move_cursor_up_action.h>
#include <fullscore/actions/paste_measure_from_buffer_action.h>
#include <fullscore/actions/reset_playback_action.h>
#include <fullscore/actions/save_measure_grid_action.h>
#include <fullscore/actions/toggle_playback_action.h>
#include <fullscore/actions/set_mode_action.h>
#include <fullscore/actions/yank_measure_to_buffer_action.h>
#include <fullscore/converters/measure_grid_file_converter.h>





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
         Action::SetMode set_mode_action(score_editor, command_bar, GUIScoreEditor::COMMAND_MODE);
         set_mode_action.execute();
      }
      break;
   case ALLEGRO_KEY_W:
      {
         Action::TransposeTransform transpose_transform_action(notes, Framework::key_shift ? 7 : 1);
         transpose_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_S:
      {
         Action::TransposeTransform transpose_transform_action(notes, Framework::key_shift ? -7 : -1);
         transpose_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_A:
      {
         Action::HalfDurationTransform half_duration_transform_action(notes);
         half_duration_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_D:
      {
         Action::DoubleDurationTransform double_duration_transform_action(notes);
         double_duration_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_R:
      {
         Action::ToggleRest toggle_rest_action(notes);
         toggle_rest_action.execute();
      }
      break;
   case ALLEGRO_KEY_E:
      {
         Action::EraseNote erase_note_action(notes, score_editor->note_cursor_x);
         erase_note_action.execute();
      }
      break;
   case ALLEGRO_KEY_I:
      {
         Action::Transform::Invert invert_action(0);
         invert_action.execute();
      }
      break;
   case ALLEGRO_KEY_G:
      {
         Action::Transform::Retrograde retrograde_action(notes);
         retrograde_action.execute();
      }
      break;
   case ALLEGRO_KEY_FULLSTOP:
      {
         Action::AddDotTransform add_dot_transform_action(notes);
         add_dot_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_COMMA:
      {
         Action::RemoveDotTransform remove_dot_transform_action(notes);
         remove_dot_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_N:
      {
         Action::InsertNoteTransform insert_note_transform_action(notes, score_editor->note_cursor_x, Note());
         insert_note_transform_action.execute();
      }
      break;
   case ALLEGRO_KEY_F1:
      {
      // ######## //
      // ######## //
         if (showing_help_menu)
         {
            // hide the help menu
            Framework::motion().cmove_to(&help_window->place.position.x, -600, 0.4);
            Framework::motion().cmove_to(&help_window->place.position.y, -100, 0.4);
            Framework::motion().cmove_to(&help_window->place.rotation, -0.1, 0.4);
            showing_help_menu = false;
         }
         else
         {
            // show the help menu
            Framework::motion().cmove_to(&help_window->place.position.x, display->center(), 0.4);
            Framework::motion().cmove_to(&help_window->place.position.y, display->middle(), 0.4);
            Framework::motion().cmove_to(&help_window->place.rotation, 0, 0.4);
            showing_help_menu = true;
         }
      }
      break;
   case ALLEGRO_KEY_F2:
      {
      // ######## //
      // ######## //
         // toggle showing the debug data on the editor
         score_editor->showing_debug_data = !score_editor->showing_debug_data;
      }
      break;
   case ALLEGRO_KEY_SPACE:
      {
         Action::TogglePlayback toggle_playback_action(score_editor, gui_mixer);
         toggle_playback_action.execute();
      }
      break;
   case ALLEGRO_KEY_Q:
      {
         Action::ResetPlayback reset_playback_action(score_editor);
         reset_playback_action.execute();
      }
      break;
   case ALLEGRO_KEY_F7:
      {
         Action::SaveMeasureGrid save_measure_grid_action(&score_editor->measure_grid, "score_filename.fs");
         if (save_measure_grid_action.execute())
            simple_notification_screen->spawn_notification("saved score as \"score_filename.fs\"");
         else
            simple_notification_screen->spawn_notification("ERROR: there was a problem saving \"score_filename.fs\"");
      }
      break;
   case ALLEGRO_KEY_F8:
      {
      // ######## //
      // ######## //
         MeasureGridFileConverter measure_grid_file_converter(&score_editor->measure_grid, "score_filename.fs");
         measure_grid_file_converter.load();
         simple_notification_screen->spawn_notification("loaded score from \"score_filename.fs\"");
      }
      break;
   case ALLEGRO_KEY_UP:
      {
      // ######## //
      // ######## //
         Framework::motion().cmove(&score_editor->place.position.y, 200, 0.4);
      }
      break;
   case ALLEGRO_KEY_DOWN:
      {
      // ######## //
      // ######## //
         Framework::motion().cmove(&score_editor->place.position.y, -200, 0.4);
      }
      break;
   case ALLEGRO_KEY_RIGHT:
      {
      // ######## //
      // ######## //
         Framework::motion().cmove(&score_editor->place.position.x, -200, 0.4);
      }
      break;
   case ALLEGRO_KEY_LEFT:
      {
      // ######## //
      // ######## //
         Framework::motion().cmove(&score_editor->place.position.x, 200, 0.4);
      }
      break;
   case ALLEGRO_KEY_EQUALS:
      {
         if (Framework::key_shift)
         {
      // ######## //
      // ######## //
            Framework::motion().cmove_to(&score_editor->place.scale.x, 1, 0.3);
            Framework::motion().cmove_to(&score_editor->place.scale.y, 1, 0.3);
         }
         else
         {
      // ######## //
      // ######## //
            Framework::motion().cmove(&score_editor->place.scale.x, 0.1, 0.4);
            Framework::motion().cmove(&score_editor->place.scale.y, 0.1, 0.4);
         }
      }
      break;
   case ALLEGRO_KEY_MINUS:
      {
      // ######## //
      // ######## //
         Framework::motion().cmove(&score_editor->place.scale.x, -0.1, 0.4);
         Framework::motion().cmove(&score_editor->place.scale.y, -0.1, 0.4);
      }
      break;
   case ALLEGRO_KEY_H:
      {
         Action::MoveCursorLeft move_cursor_left_action(score_editor);
         move_cursor_left_action.execute();
      }
      break;
   case ALLEGRO_KEY_J:
      {
         Action::MoveCursorDown move_cursor_down_action(score_editor);
         move_cursor_down_action.execute();
      }
      break;
   case ALLEGRO_KEY_K:
      {
         Action::MoveCursorUp move_cursor_up_action(score_editor);
         move_cursor_up_action.execute();
      }
      break;
   case ALLEGRO_KEY_L:
      {
         Action::MoveCursorRight move_cursor_right_action(score_editor);
         move_cursor_right_action.execute();
      }
      break;
   case ALLEGRO_KEY_Y:
      {
         Measure *focused_measure = score_editor->get_measure_at_cursor();
         Action::YankMeasureToBuffer yank_measure_to_buffer_action(&yank_measure_buffer, focused_measure);
         yank_measure_to_buffer_action.execute();
      }
      break;
   case ALLEGRO_KEY_P:
      {
         Measure *destination_measure = score_editor->get_measure_at_cursor();
         Action::PasteMeasureFromBuffer paste_measure_from_buffer_action(destination_measure, &yank_measure_buffer);
         paste_measure_from_buffer_action.execute();
      }
      break;
   case ALLEGRO_KEY_TAB:
      // ######## //
      // ######## //
      score_editor->toggle_edit_mode_target();
      break;
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




