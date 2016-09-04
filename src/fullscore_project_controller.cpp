



#include <fullscore/fullscore_project_controller.h>




FullscoreProjectController::FullscoreProjectController(Display *display)
   : UIScreen(display)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , score_editor(NULL)
   , command_bar(NULL)
   , gui_mixer(NULL)
   , help_window(NULL)
   , showing_help_menu(false)
{
   UIScreen::draw_focused_outline = false;

   score_editor = new GUIScoreEditor(this, display, new PlaybackDeviceGeneric());
   gui_mixer = new UIMixer(this, 1350, 500);
   command_bar = new UICommandBar(this);

   simple_notification_screen->spawn_notification("Press F1 for help");

   create_help_window();
}




void FullscoreProjectController::create_help_window()
{
   help_window = new UIFramedWindow(this, -600, -100, 550, 700);
   help_window->set_title("Help");

   UIText *help_title = new UIText(help_window, 25, 25, "Controls");
   UITextBox *help_paragraph = new UITextBox(help_window, 25, 25+70, 500, 500, php::file_get_contents("data/documents/help.txt"));

   help_paragraph->set_text_color(color::white);

   help_title->place.align = vec2d(0, 0);
   help_paragraph->place.align = vec2d(0, 0);
}




void FullscoreProjectController::primary_timer_func()
{
   UIScreen::primary_timer_func();
   command_bar->set_time(score_editor->playback_control.position);
}




void FullscoreProjectController::key_down_func()
{
   UIScreen::key_down_func();


   if (Framework::current_event->keyboard.keycode == ALLEGRO_KEY_SEMICOLON)
   {
      // toggle focus of the command bar

      if (command_bar->text_input->is_focused()) command_bar->text_input->set_as_unfocused();
      else command_bar->text_input->set_as_focused();
   }
   else if (!command_bar->text_input->is_focused())
   {
      // while the command bar is NOT focused, here are the normal keyboard inputs

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
         on_message(this, "cursor_left");
         break;
      case ALLEGRO_KEY_J:
         on_message(this, "cursor_down");
         break;
      case ALLEGRO_KEY_K:
         on_message(this, "cursor_up");
         break;
      case ALLEGRO_KEY_L:
         on_message(this, "cursor_right");
         break;
      case ALLEGRO_KEY_TAB:
         score_editor->toggle_input_mode();
         break;
      }
   }
}




void FullscoreProjectController::on_message(UIWidget *sender, std::string message)
{
   std::cout << "message: " << message << std::endl;
   if (message == "toggle_playback") score_editor->playback_control.toggle_playback();
   if (message == "reset_playback") score_editor->playback_control.reset();

   if (message == "cursor_left")
   {
      if (score_editor->is_measure_mode())
      {
         score_editor->move_measure_cursor_x(-1);
         score_editor->note_cursor_x = 0;
      }
      else if (score_editor->is_note_mode()) score_editor->move_note_cursor_x(-1);
   }
   if (message == "cursor_right")
   {
      if (score_editor->is_measure_mode())
      {
         score_editor->move_measure_cursor_x(1);
         score_editor->note_cursor_x = 0;
      }
      else if (score_editor->is_note_mode()) score_editor->move_note_cursor_x(1);
   }
   if (message == "cursor_up") score_editor->move_measure_cursor_y(-1);
   if (message == "cursor_down") score_editor->move_measure_cursor_y(1);

   if (message == "insert_measure")
      score_editor->measure_grid.insert_measure(score_editor->get_hovered_measure_index());
   if (message == "delete_measure")
      score_editor->measure_grid.delete_measure(score_editor->get_hovered_measure_index());
   if (message == "insert_staff")
      score_editor->measure_grid.insert_staff(score_editor->get_hovered_staff_index());
   if (message == "delete_staff")
      score_editor->measure_grid.delete_staff(score_editor->get_hovered_staff_index());
}




