



#include <fullscore/fullscore_application_controller.h>

#include <fullscore/actions/move_cursor_left_action.h>
#include <fullscore/actions/move_cursor_right_action.h>
#include <fullscore/actions/move_cursor_up_action.h>
#include <fullscore/actions/toggle_command_bar_action.h>
#include <fullscore/transforms/double_duration_transform.h>
#include <fullscore/transforms/erase_note_transform.h>
#include <fullscore/transforms/half_duration_transform.h>
#include <fullscore/transforms/insert_note_transform.h>
#include <fullscore/transforms/invert_transform.h>
#include <fullscore/transforms/retrograde_transform.h>
#include <fullscore/transforms/transpose_transform.h>
#include <fullscore/transforms/toggle_rest_transform.h>





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
   gui_mixer = new UIMixer(this, 1350, 500);
   command_bar = new UICommandBar(this);

   simple_notification_screen->spawn_notification("Press F1 for help");

   create_help_window();
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




void FullscoreApplicationController::key_down_func()
{
   UIScreen::key_down_func();


   if (Framework::current_event->keyboard.keycode == ALLEGRO_KEY_SEMICOLON)
   {
      Action::ToggleCommandBar toggle_command_bar_action(command_bar);
      toggle_command_bar_action.execute();
   }
   else if (!command_bar->text_input->is_focused())
   {
      //
      // SCORE EDITING COMMANDS
      //

      std::vector<Note> *notes = nullptr;
      Note *note = nullptr;
      Transform::Base *transform = nullptr;

      // find the note/notes to transform
      if (score_editor->is_measure_mode())
      {
         Measure *focused_measure = score_editor->get_measure_at_cursor();
         if (focused_measure) notes = &focused_measure->notes;
      }
      else
      {
         Note *focused_note = score_editor->get_note_at_cursor();
         if (focused_note) note = focused_note;
      }

      // locate and build the appropriate transform
      switch(Framework::current_event->keyboard.keycode)
      {
      case ALLEGRO_KEY_W:
         // transpose up
         {
            // create the transformation
            Transform::Transpose transpose_transform(0);

            // find the amount of the transformation
            if (Framework::key_shift) transpose_transform.transposition = 7;
            else if (Framework::key_ctrl); // nothing (this add flats to the whole measure? .. probably not a feature to have)
            else transpose_transform.transposition = 1;

            // assign the transformation
            transform = &transpose_transform;
         }
         break;
      case ALLEGRO_KEY_S:
         // transpose down
         {
            // create the transformation
            Transform::Transpose transpose_transform(0);

            // find the amount of the transformation
            if (Framework::key_shift) transpose_transform.transposition = -7;
            else if (Framework::key_ctrl); // nothing (this add sharps to the whole measure? .. probably not a feature to have)
            else transpose_transform.transposition = -1;

            // assign the transformation
            transform = &transpose_transform;
         }
         break;
      case ALLEGRO_KEY_A:
         {
            Transform::HalfDuration half_duration_transform;
            transform = &half_duration_transform;
         }
         break;
      case ALLEGRO_KEY_D:
         {
            Transform::DoubleDuration double_duration_transform;
            transform = &double_duration_transform;
         }
         break;
      case ALLEGRO_KEY_R:
         {
            Transform::ToggleRest toggle_rest_transform;
            transform = &toggle_rest_transform;
         }
         break;
      case ALLEGRO_KEY_E:
         // erase the focused note
         {
            Transform::EraseNote erase_note_transform(score_editor->note_cursor_x);
            transform = &erase_note_transform;
         }
         break;
      case ALLEGRO_KEY_I:
         // invert the measure
         {
            Transform::Invert invert_transform(0);
            transform = &invert_transform;
         }
         break;
      case ALLEGRO_KEY_G:
         // retrograde the measure
         {
            Transform::Retrograde retrograde_transform;
            transform = &retrograde_transform;
         }
         break;
      case ALLEGRO_KEY_FULLSTOP:
         // add a dot
         {
            Note *focused_note = score_editor->get_note_at_cursor();
            if (!focused_note) break;
            focused_note->dots = std::min(2, focused_note->dots+1);
         }
         break;
      case ALLEGRO_KEY_COMMA:
         // remove a dot
         {
            Note *focused_note = score_editor->get_note_at_cursor();
            if (!focused_note) break;
            focused_note->dots = std::max(0, focused_note->dots-1);
         }
         break;

      case ALLEGRO_KEY_N:
         {
            Transform::InsertNote insert_note_transform(score_editor->note_cursor_x, Note());
            transform = &insert_note_transform;
         }
         break;
      case ALLEGRO_KEY_M:
         {
            // append a measure
            score_editor->measure_grid.push_measure();
         }
         break;
      case ALLEGRO_KEY_T:
         {
            // append a staff
            score_editor->measure_grid.push_staff();
         }
         break;
      case ALLEGRO_KEY_Y:
         if (notes) yank_measure_buffer.notes = *notes;
         std::cout << "AAAA" << std::endl;
         break;
      case ALLEGRO_KEY_P:
         *notes = yank_measure_buffer.notes;
         break;
      default:
         break;
      }

      // perform the actual transformation
      if (transform)
      {
         if (note) *note = transform->transform({*note})[0];
         else if (notes) *notes = transform->transform(*notes);
      }
      // while the command bar is NOT focused, here are the normal keyboard inputs

      //
      // NON-SCORE EDITING COMMANDS
      //

      switch(Framework::current_event->keyboard.keycode)
      {
      case ALLEGRO_KEY_F1:
         {
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
            // toggle showing the debug data on the editor
            score_editor->showing_debug_data = !score_editor->showing_debug_data;
         }
         break;
      case ALLEGRO_KEY_SPACE:
         {
            // send the patches before play
            PlaybackDeviceInterface *device = score_editor->playback_control.playback_device;
            for (unsigned i=0; i<score_editor->measure_grid.get_num_staves(); i++)
            {
               device->patch_change(i, gui_mixer->get_patch_num(i));
            }
            // toggle playback
            score_editor->playback_control.toggle_playback();
         }
         break;
      case ALLEGRO_KEY_Q:
         {
            // toggle playback
            score_editor->playback_control.reset();
         }
         break;
      case ALLEGRO_KEY_F7:
         {
            score_editor->measure_grid.save("score_filename.fs");
            simple_notification_screen->spawn_notification("saved score as \"score_filename.fs\"");
         }
         break;
      case ALLEGRO_KEY_F8:
         {
            score_editor->measure_grid.load("score_filename.fs");
            simple_notification_screen->spawn_notification("loaded score from \"score_filename.fs\"");
         }
         break;

      // some basic placement controls of this widget

      case ALLEGRO_KEY_UP:
         {
            Framework::motion().cmove(&score_editor->place.position.y, 200, 0.4);
         }
         break;
      case ALLEGRO_KEY_DOWN:
         {
            Framework::motion().cmove(&score_editor->place.position.y, -200, 0.4);
         }
         break;
      case ALLEGRO_KEY_RIGHT:
         {
            Framework::motion().cmove(&score_editor->place.position.x, -200, 0.4);
         }
         break;
      case ALLEGRO_KEY_LEFT:
         {
            Framework::motion().cmove(&score_editor->place.position.x, 200, 0.4);
         }
         break;
      case ALLEGRO_KEY_EQUALS:
         {
            if (Framework::key_shift)
            {
               Framework::motion().cmove_to(&score_editor->place.scale.x, 1, 0.3);
               Framework::motion().cmove_to(&score_editor->place.scale.y, 1, 0.3);
            }
            else
            {
               Framework::motion().cmove(&score_editor->place.scale.x, 0.1, 0.4);
               Framework::motion().cmove(&score_editor->place.scale.y, 0.1, 0.4);
            }
         }
         break;
      case ALLEGRO_KEY_MINUS:
         {
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
         on_message(this, "cursor_down");
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
      case ALLEGRO_KEY_TAB:
         score_editor->toggle_input_mode();
         break;
      }
   }
}




void FullscoreApplicationController::on_message(UIWidget *sender, std::string message)
{
   std::cout << "message: " << message << std::endl;
   if (message == "toggle_playback") score_editor->playback_control.toggle_playback();
   if (message == "reset_playback") score_editor->playback_control.reset();

   if (message == "cursor_down") score_editor->move_measure_cursor_y(1);

   if (message == "insert_measure")
      score_editor->measure_grid.insert_measure(score_editor->measure_cursor_x);
   if (message == "delete_measure")
      score_editor->measure_grid.delete_measure(score_editor->measure_cursor_x);
   if (message == "insert_staff")
      score_editor->measure_grid.insert_staff(score_editor->measure_cursor_y);
   if (message == "delete_staff")
      score_editor->measure_grid.delete_staff(score_editor->measure_cursor_y);
}




