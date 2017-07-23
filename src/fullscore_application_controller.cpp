



#include <fullscore/fullscore_application_controller.h>

#include <fullscore/transforms/reference.h>
#include <fullscore/transforms/double_duration.h>

#include <fullscore/actions/transforms/add_dot_transform_action.h>
#include <fullscore/actions/transforms/clear_measure_transform_action.h>
#include <fullscore/actions/transforms/double_duration_transform_action.h>
#include <fullscore/actions/transforms/erase_note_action.h>
#include <fullscore/actions/transforms/half_duration_transform_action.h>
#include <fullscore/actions/transforms/insert_note_action.h>
#include <fullscore/actions/transforms/invert_action.h>
#include <fullscore/actions/transforms/octatonic_1_transform_action.h>
#include <fullscore/actions/transforms/remove_dot_transform_action.h>
#include <fullscore/actions/transforms/retrograde_action.h>
#include <fullscore/actions/transforms/toggle_rest_action.h>
#include <fullscore/actions/transforms/transpose_up_action.h>
#include <fullscore/actions/transforms/transpose_down_action.h>
#include <fullscore/actions/append_measure_action.h>
#include <fullscore/actions/append_staff_action.h>
#include <fullscore/actions/create_new_score_editor_action.h>
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
#include <fullscore/actions/queue_action.h>
#include <fullscore/actions/reset_playback_action.h>
#include <fullscore/actions/save_measure_grid_action.h>
#include <fullscore/actions/set_basic_measure_action.h>
#include <fullscore/actions/set_camera_target_action.h>
#include <fullscore/actions/set_command_mode_action.h>
#include <fullscore/actions/set_current_gui_score_editor_action.h>
#include <fullscore/actions/set_mode_action.h>
#include <fullscore/actions/set_normal_mode_action.h>
#include <fullscore/actions/set_reference_cursor_action.h>
#include <fullscore/actions/set_reference_measure_action.h>
#include <fullscore/actions/set_score_zoom_action.h>
#include <fullscore/actions/set_stack_measure_action.h>
#include <fullscore/actions/start_motion_action.h>
#include <fullscore/actions/toggle_edit_mode_target_action.h>
#include <fullscore/actions/toggle_playback_action.h>
#include <fullscore/actions/toggle_show_debug_data_action.h>
#include <fullscore/actions/yank_measure_to_buffer_action.h>

#include <fullscore/factories/measure_grid_factory.h>

#include <fullscore/models/measures/static.h>



FullscoreApplicationController::FullscoreApplicationController(Display *display)
   : UIScreen(display)
   , simple_notification_screen(new SimpleNotificationScreen(display, Framework::font("DroidSans.ttf 20")))
   , action_queue("master_queue")
   , follow_camera(this)
   , current_gui_score_editor(nullptr)
   , gui_score_editors()
   , command_bar(new UICommandBar(this))
   , ui_measure_inspector(new UIMeasureInspector(this))
   , yank_measure_buffer()
   , reference_cursor(nullptr, 0, 0)
{
   UIScreen::draw_focused_outline = false;

   create_new_score_editor("");
   set_current_gui_score_editor(create_new_score_editor("big_score"));

   current_gui_score_editor->measure_grid.set_measure(0, 0, new Measure::Basic({Note(2), Note(0), Note(1)}));
   Measure::Base *m = current_gui_score_editor->measure_grid.get_measure(0, 0);
   if (!m) throw std::runtime_error("hmm, ApplicationController not able to set/get a measure from the MeasureGrid (0, 0)");

   current_gui_score_editor->measure_grid.set_measure(0, 1, new Measure::Basic());
   Measure::Basic *dm = static_cast<Measure::Basic *>(current_gui_score_editor->measure_grid.get_measure(0, 1));
   if (!dm) throw std::runtime_error("hmm, ApplicationController not able to set/get a measure from the MeasureGrid (0, 1)");

   Transform::Reference reference_transform(&current_gui_score_editor->measure_grid, 0, 0);
   Transform::DoubleDuration double_duration_transform;
   dm->genesis = new Transform::Stack();
   dm->genesis->add_transform(&reference_transform);
   dm->genesis->add_transform(&double_duration_transform);
   dm->refresh();

   current_gui_score_editor->measure_grid.set_measure(0, 3, new Measure::Static());

   follow_camera.target.position.y = 200;
   follow_camera.target.position.x = 200;
}




void FullscoreApplicationController::primary_timer_func()
{
   UIScreen::primary_timer_func();
   if (ui_measure_inspector) ui_measure_inspector->set_measure(current_gui_score_editor->get_measure_at_cursor());
   ui_measure_inspector->place.position = vec2d(display->width(), 0);
   ui_measure_inspector->place.size = vec2d(300, display->height());
}




std::string FullscoreApplicationController::find_action_identifier(GUIScoreEditor::mode_t mode, int al_keycode, bool shift, bool ctrl, bool alt)
{
   switch(al_keycode)
   {
      case ALLEGRO_KEY_N: if(ctrl) return "create_new_score_editor"; break;
      case ALLEGRO_KEY_X: if(ctrl) return "set_current_gui_score_editor"; break;
      case ALLEGRO_KEY_UP: return "move_camera_up"; break;
      case ALLEGRO_KEY_DOWN: return "move_camera_down"; break;
      case ALLEGRO_KEY_RIGHT: return "move_camera_right"; break;
      case ALLEGRO_KEY_LEFT: return "move_camera_left"; break;
   }

   if (mode == GUIScoreEditor::NORMAL_MODE)
      switch(al_keycode)
      {
      case ALLEGRO_KEY_F: return "transpose_up"; break;
      case ALLEGRO_KEY_D: return "transpose_down"; break;
      case ALLEGRO_KEY_S: if (shift) { return "set_stack_measure"; } else { return "half_duration"; } break;
      case ALLEGRO_KEY_G: return "double_duration"; break;
      case ALLEGRO_KEY_R: if (shift) { return "set_reference_measure"; } else { return "toggle_rest"; } break;
      case ALLEGRO_KEY_C: if (shift) return "set_reference_cursor"; break;
      case ALLEGRO_KEY_N: return "invert"; break;
      case ALLEGRO_KEY_FULLSTOP: return "add_dot"; break;
      case ALLEGRO_KEY_COMMA: return "remove_dot"; break;
      case ALLEGRO_KEY_SEMICOLON: return "set_command_mode"; break;
      case ALLEGRO_KEY_X: return "erase_note"; break;
      case ALLEGRO_KEY_Z: return "retrograde"; break;
      case ALLEGRO_KEY_I: return "insert_note"; break;
      case ALLEGRO_KEY_F2: return "toggle_show_debug_data"; break;
      case ALLEGRO_KEY_SPACE: return "toggle_playback"; break;
      case ALLEGRO_KEY_Q: return "reset_playback"; break;
      case ALLEGRO_KEY_F7: return "save_measure_grid"; break;
      case ALLEGRO_KEY_F8: return "load_measure_grid"; break;
      case ALLEGRO_KEY_EQUALS: return shift ? "camera_zoom_default" : "camera_zoom_in"; break;
      case ALLEGRO_KEY_MINUS: return "camera_zoom_out"; break;
      case ALLEGRO_KEY_H: return "move_cursor_left"; break;
      case ALLEGRO_KEY_J: return "move_cursor_down"; break;
      case ALLEGRO_KEY_K: return "move_cursor_up"; break;
      case ALLEGRO_KEY_L: return "move_cursor_right"; break;
      case ALLEGRO_KEY_M: if(shift) return "set_basic_measure"; break;
      case ALLEGRO_KEY_Y: return "yank_measure_to_buffer"; break;
      case ALLEGRO_KEY_P: return "paste_measure_from_buffer"; break;
      case ALLEGRO_KEY_O: return "octatonic_1_transform"; break;
      case ALLEGRO_KEY_TAB: return "toggle_edit_mode_target"; break;
      }

   if (mode == GUIScoreEditor::COMMAND_MODE)
      switch(al_keycode)
      {
      case ALLEGRO_KEY_SEMICOLON: return "set_normal_mode"; break;
      }

   if (mode == GUIScoreEditor::INSERT_MODE)
      // no implementation
      ;

   return "";
}




Action::Base *FullscoreApplicationController::create_action(std::string action_name)
{
   //
   // APP COMMANDS
   //

   Action::Base *action = nullptr;

   if (action_name == "create_new_score_editor")
      action = new Action::CreateNewScoreEditor(this);
   else if (action_name == "set_current_gui_score_editor")
      action = new Action::SetCurrentGUIScoreEditor(this, get_next_gui_score_editor());
   else if (action_name == "move_camera_up")
      action = new Action::SetCameraTarget(&follow_camera, follow_camera.target.position.x, follow_camera.target.position.y + 100);
   else if (action_name == "move_camera_down")
      action = new Action::SetCameraTarget(&follow_camera, follow_camera.target.position.x, follow_camera.target.position.y - 100);
   else if (action_name == "move_camera_right")
      action = new Action::SetCameraTarget(&follow_camera, follow_camera.target.position.x - 100, follow_camera.target.position.y);
   else if (action_name == "move_camera_left")
      action = new Action::SetCameraTarget(&follow_camera, follow_camera.target.position.x + 100, follow_camera.target.position.y);

   if (action) return action;


   //
   // SCORE EDITING COMMANDS
   //

   if (!current_gui_score_editor) return nullptr;

   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   Measure::Base *focused_measure = nullptr;

   if (current_gui_score_editor->is_note_target_mode())
   {
      single_note = current_gui_score_editor->get_note_at_cursor();
      focused_measure = current_gui_score_editor->get_measure_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }
   if (current_gui_score_editor->is_measure_target_mode())
   {
      focused_measure = current_gui_score_editor->get_measure_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }

   if (action_name == "transpose_up")
   {
      if (current_gui_score_editor->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::TransposeUp(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_up on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::TransposeUp(&note));
         return action_queue;
      }
   }
   else if (action_name == "transpose_down")
   {
      if (current_gui_score_editor->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::TransposeDown(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_down on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::TransposeDown(&note));
         return action_queue;
      }
   }
   else if (action_name == "half_duration")
   {
      if (current_gui_score_editor->is_note_target_mode()) action = new Action::HalfDurationTransform(single_note);
      else
      {
         if (!notes) { std::cout << "cannot half_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::HalfDurationTransform(&note));
         return action_queue;
      }
   }
   else if (action_name == "double_duration")
   {
      if (current_gui_score_editor->is_note_target_mode()) action = new Action::DoubleDurationTransform(single_note);
      else
      {
         if (!notes) { std::cout << "cannot double_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::DoubleDurationTransform(&note));
         return action_queue;
      }
   }
   else if (action_name == "toggle_rest")
   {
      if (current_gui_score_editor->is_note_target_mode()) action = new Action::ToggleRest(single_note);
      else
      {
         if (!notes) { std::cout << "cannot toggle_rest on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::ToggleRest(&note));
         return action_queue;
      }
   }
   else if (action_name == "erase_note")
   {
      if (current_gui_score_editor->is_note_target_mode()) action = new Action::EraseNote(notes, current_gui_score_editor->note_cursor_x);
      else if (current_gui_score_editor->is_measure_target_mode()) action = new Action::Transform::ClearMeasure(notes); // TODO this should be changed to SetMeasure(nullptr) or something to that effect
   }
   else if (action_name == "invert")
      action = new Action::Transform::Invert(single_note, 0);
   else if (action_name == "add_dot")
      action = new Action::AddDotTransform(single_note);
   else if (action_name == "remove_dot")
      action = new Action::RemoveDotTransform(single_note);
   else if (action_name == "set_command_mode")
      action = new Action::SetCommandMode(current_gui_score_editor, command_bar);
   else if (action_name == "set_normal_mode")
      action = new Action::SetNormalMode(current_gui_score_editor, command_bar);
   else if (action_name == "retrograde")
      action = new Action::Transform::Retrograde(notes);
   else if (action_name == "octatonic_1_transform")
      action = new Action::Octatonic1Transform(notes);
   else if (action_name == "insert_note")
      action = new Action::InsertNoteTransform(notes, current_gui_score_editor->note_cursor_x, Note());
   else if (action_name == "toggle_show_debug_data")
      action = new Action::ToggleShowDebugData(current_gui_score_editor);
   else if (action_name == "toggle_playback")
      action = new Action::TogglePlayback(&current_gui_score_editor->playback_control);
   else if (action_name == "reset_playback")
      action = new Action::ResetPlayback(current_gui_score_editor);
   else if (action_name == "save_measure_grid")
      action = new Action::SaveMeasureGrid(&current_gui_score_editor->measure_grid, "score_filename.fs");
   else if (action_name == "load_measure_grid")
      action = new Action::LoadMeasureGrid(&current_gui_score_editor->measure_grid, "score_filename.fs");
   else if (action_name == "camera_zoom_in")
      action = new Action::SetScoreZoom(current_gui_score_editor, &Framework::motion(), current_gui_score_editor->place.scale.x + 0.1, 0.3);
   else if (action_name == "camera_zoom_default")
      action = new Action::SetScoreZoom(current_gui_score_editor, &Framework::motion(), 1, 0.3);
   else if (action_name == "camera_zoom_out")
      action = new Action::SetScoreZoom(current_gui_score_editor, &Framework::motion(), current_gui_score_editor->place.scale.x - 0.1, 0.3);
   else if (action_name == "move_cursor_left")
      action = new Action::MoveCursorLeft(current_gui_score_editor);
   else if (action_name == "move_cursor_down")
      action = new Action::MoveCursorDown(current_gui_score_editor);
   else if (action_name == "move_cursor_up")
      action = new Action::MoveCursorUp(current_gui_score_editor);
   else if (action_name == "move_cursor_right")
      action = new Action::MoveCursorRight(current_gui_score_editor);
   else if (action_name == "yank_measure_to_buffer")
      action = new Action::YankMeasureToBuffer(&yank_measure_buffer, focused_measure);
   else if (action_name == "paste_measure_from_buffer")
      action = new Action::PasteMeasureFromBuffer(focused_measure, &yank_measure_buffer);
   else if (action_name == "toggle_edit_mode_target")
      action = new Action::ToggleEditModeTarget(current_gui_score_editor);
   else if (action_name == "set_reference_measure")
      action = new Action::SetReferenceMeasure(
            &current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_x, current_gui_score_editor->measure_cursor_y,
            &current_gui_score_editor->measure_grid, 0, 0);
   else if (action_name == "set_reference_cursor")
      action = new Action::SetReferenceCursor(&reference_cursor,
            &current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_x, current_gui_score_editor->measure_cursor_y);
   else if (action_name == "set_basic_measure")
      action = new Action::SetBasicMeasure(&current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_x, current_gui_score_editor->measure_cursor_y);
   else if (action_name == "set_stack_measure")
      action = new Action::SetStackMeasure(&current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_x, current_gui_score_editor->measure_cursor_y);
   else if (action_name == "insert_measure")
      action = new Action::InsertMeasure(&current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_x);
   else if (action_name == "delete_measure")
      action = new Action::DeleteMeasure(&current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_x);
   else if (action_name == "insert_staff")
      action = new Action::InsertStaff(&current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_y);
   else if (action_name == "delete_staff")
      action = new Action::DeleteStaff(&current_gui_score_editor->measure_grid, current_gui_score_editor->measure_cursor_y);
   else if (action_name == "append_measure")
      action = new Action::AppendMeasure(&current_gui_score_editor->measure_grid);
   else if (action_name == "append_staff")
      action = new Action::AppendStaff(&current_gui_score_editor->measure_grid);

   return action;
}




void FullscoreApplicationController::key_down_func()
{
   UIScreen::key_down_func();

   auto mode          = current_gui_score_editor ? current_gui_score_editor->mode : GUIScoreEditor::mode_t::NONE;
   auto keycode       = Framework::current_event->keyboard.keycode;
   auto shift_pressed = Framework::key_shift;
   auto alt_pressed   = Framework::key_alt;
   auto ctrl_pressed  = Framework::key_ctrl;

   std::string identifier = find_action_identifier(mode, keycode, shift_pressed, ctrl_pressed, alt_pressed);
   Action::Base *action = create_action(identifier);

   if (action)
   {
      try
      {
         if (!action->execute()) throw std::runtime_error("Generic could-not-execute-action exception");
      }
      catch (const std::runtime_error& e)
      {
         std::cout << "Exception caught while trying to run action "
                   << action->get_action_name()
                   << " with the following message \""
                   << e.what()
                   << "\""
                   << std::endl;
      }
      delete action;
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

            Action::SetNormalMode return_to_normal_mode(current_gui_score_editor, command_bar);
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

         Action::SetNormalMode return_to_normal_mode(current_gui_score_editor, command_bar);
         return_to_normal_mode.execute();
      }
   }
}




GUIScoreEditor *FullscoreApplicationController::create_new_score_editor(std::string name)
{
   static int new_x = 0;
   static int new_y = 0;

   GUIScoreEditor *new_gui_score_editor = new GUIScoreEditor(&follow_camera);
   new_gui_score_editor->measure_grid = MeasureGridFactory::create(name);

   new_gui_score_editor->place.position = vec2d(new_x, new_y);
   new_gui_score_editor->place.align = vec2d(0.0, 0.0);

   gui_score_editors.push_back(new_gui_score_editor);

   new_y += 300;

   return new_gui_score_editor;
}




bool FullscoreApplicationController::set_current_gui_score_editor(GUIScoreEditor *editor)
{
   if (std::find(gui_score_editors.begin(), gui_score_editors.end(), editor) == gui_score_editors.end()) return false;

   for (auto &e : gui_score_editors)
      e->set_state(e == editor ? GUIScoreEditor::STATE_ACTIVE : GUIScoreEditor::STATE_INACTIVE);

   current_gui_score_editor = editor;

   // move the camera to the new current_gui_score_editor
   follow_camera.target.position = -current_gui_score_editor->place.position + vec2d(200, 200);

   return true;
}




GUIScoreEditor *FullscoreApplicationController::get_next_gui_score_editor()
{
   if (!current_gui_score_editor || gui_score_editors.size() <= 1) return nullptr;

   std::vector<GUIScoreEditor *>::iterator it = std::find(gui_score_editors.begin(), gui_score_editors.end(), current_gui_score_editor);

   if (it == gui_score_editors.end()) return nullptr; // does not exist in list
   if (it == gui_score_editors.end()-1) return gui_score_editors.front(); // loop back to first element
   ++it;
   return *it;
}




