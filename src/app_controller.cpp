



#include <fullscore/app_controller.h>

#include <fullscore/actions/transforms/append_note_action.h>
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
#include <fullscore/actions/append_column_to_grid_action.h>
#include <fullscore/actions/append_staff_action.h>
#include <fullscore/actions/create_new_grid_editor_action.h>
#include <fullscore/actions/delete_measure_action.h>
#include <fullscore/actions/delete_grid_column_action.h>
#include <fullscore/actions/delete_staff_action.h>
#include <fullscore/actions/insert_column_action.h>
#include <fullscore/actions/insert_staff_action.h>
#include <fullscore/actions/load_grid_action.h>
#include <fullscore/actions/move_cursor_down_action.h>
#include <fullscore/actions/move_cursor_left_action.h>
#include <fullscore/actions/move_cursor_right_action.h>
#include <fullscore/actions/move_cursor_up_action.h>
#include <fullscore/actions/paste_measure_from_buffer_action.h>
#include <fullscore/actions/paste_measure_from_buffer_to_grid_coordinates_action.h>
#include <fullscore/actions/queue_action.h>
#include <fullscore/actions/reset_playback_action.h>
#include <fullscore/actions/save_grid_action.h>
#include <fullscore/actions/set_basic_measure_action.h>
#include <fullscore/actions/set_camera_target_action.h>
#include <fullscore/actions/set_command_mode_action.h>
#include <fullscore/actions/set_current_grid_editor_action.h>
#include <fullscore/actions/set_mode_action.h>
#include <fullscore/actions/set_normal_mode_action.h>
#include <fullscore/actions/set_reference_cursor_action.h>
#include <fullscore/actions/set_reference_by_coordinate_measure_action.h>
#include <fullscore/actions/set_reference_by_id_measure_action.h>
#include <fullscore/actions/set_score_zoom_action.h>
#include <fullscore/actions/set_stack_measure_action.h>
#include <fullscore/actions/set_time_signature_numerator_action.h>
#include <fullscore/actions/start_motion_action.h>
#include <fullscore/actions/toggle_edit_mode_target_action.h>
#include <fullscore/actions/toggle_playback_action.h>
#include <fullscore/actions/toggle_show_debug_data_action.h>
#include <fullscore/actions/yank_measure_to_buffer_action.h>
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
      case ALLEGRO_KEY_F: return "transpose_up"; break;
      case ALLEGRO_KEY_D: return "transpose_down"; break;
      case ALLEGRO_KEY_S: if (shift) { return "set_stack_measure"; } else { return "half_duration"; } break;
      case ALLEGRO_KEY_G: return "double_duration"; break;
      case ALLEGRO_KEY_7: if (shift) { return "set_reference_by_id_measure"; } break;
      case ALLEGRO_KEY_8: if (shift) { return "set_reference_by_coordinate_measure"; } break;
      case ALLEGRO_KEY_R: return "toggle_rest"; break;
      case ALLEGRO_KEY_C: if (shift) return "set_reference_cursor"; break;
      case ALLEGRO_KEY_N: return "invert"; break;
      case ALLEGRO_KEY_FULLSTOP: return "add_dot"; break;
      case ALLEGRO_KEY_COMMA: return "remove_dot"; break;
      case ALLEGRO_KEY_SEMICOLON: return "set_command_mode"; break;
      case ALLEGRO_KEY_X:
         if (edit_mode_target == UIGridEditor::edit_mode_target_t::NOTE_TARGET) { return "erase_note"; }
         else if (edit_mode_target == UIGridEditor::edit_mode_target_t::MEASURE_TARGET) { return "delete_measure"; }
         break;
      case ALLEGRO_KEY_Z: return "retrograde"; break;
      case ALLEGRO_KEY_A: return "insert_note_after"; break;
      case ALLEGRO_KEY_I: return "insert_note"; break;
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
      case ALLEGRO_KEY_O: return "octatonic_1_transform"; break;
      case ALLEGRO_KEY_TAB: return "toggle_edit_mode_target"; break;
      case ALLEGRO_KEY_2: return "set_time_signature_numerator_2"; break;
      case ALLEGRO_KEY_3: return "set_time_signature_numerator_3"; break;
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




Action::Base *AppController::create_action(std::string action_name)
{
   //
   // APP COMMANDS
   //

   Action::Base *action = nullptr;

   if (action_name == "create_new_grid_editor")
      action = new Action::CreateNewScoreEditor(this);
   else if (action_name == "set_current_grid_editor")
      action = new Action::SetCurrentUIGridEditor(this, get_next_grid_editor());
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

   if (!current_grid_editor) return nullptr;

   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   Measure::Base *focused_measure = nullptr;
   Measure::Base *measure_at_reference_cursor = nullptr;

   if (reference_cursor.is_valid())
   {
      measure_at_reference_cursor = reference_cursor.get_grid()->get_measure(reference_cursor.get_x(), reference_cursor.get_y());
   }

   if (current_grid_editor->is_note_target_mode())
   {
      single_note = current_grid_editor->get_note_at_cursor();
      focused_measure = current_grid_editor->get_measure_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }
   if (current_grid_editor->is_measure_target_mode())
   {
      focused_measure = current_grid_editor->get_measure_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }

   if (action_name == "transpose_up")
   {
      if (current_grid_editor->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::Transform::TransposeUp(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_up on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::Transform::TransposeUp(&note));
         return action_queue;
      }
   }
   else if (action_name == "transpose_down")
   {
      if (current_grid_editor->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::Transform::TransposeDown(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_down on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::Transform::TransposeDown(&note));
         return action_queue;
      }
   }
   else if (action_name == "half_duration")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::HalfDuration(single_note);
      else
      {
         if (!notes) { std::cout << "cannot half_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::HalfDuration(&note));
         return action_queue;
      }
   }
   else if (action_name == "double_duration")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::DoubleDuration(single_note);
      else
      {
         if (!notes) { std::cout << "cannot double_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::DoubleDuration(&note));
         return action_queue;
      }
   }
   else if (action_name == "toggle_rest")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::ToggleRest(single_note);
      else
      {
         if (!notes) { std::cout << "cannot toggle_rest on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::ToggleRest(&note));
         return action_queue;
      }
   }
   else if (action_name == "erase_note")
      action = new Action::Transform::EraseNote(notes, current_grid_editor->note_cursor_x);
   else if (action_name == "invert")
      action = new Action::Transform::Invert(single_note, 0);
   else if (action_name == "add_dot")
      action = new Action::Transform::AddDot(single_note);
   else if (action_name == "remove_dot")
      action = new Action::Transform::RemoveDot(single_note);
   else if (action_name == "set_command_mode")
      action = new Action::SetCommandMode(current_grid_editor, command_bar);
   else if (action_name == "set_normal_mode")
      action = new Action::SetNormalMode(current_grid_editor, command_bar);
   else if (action_name == "retrograde")
      action = new Action::Transform::Retrograde(notes);
   else if (action_name == "octatonic_1_transform")
      action = new Action::Transform::Octatonic1(notes);
   else if (action_name == "insert_note")
      action = new Action::Transform::InsertNote(notes, current_grid_editor->note_cursor_x, Note());
   else if (action_name == "insert_note_after")
   {
      action = new Action::Queue("insert_note_after: insert_note and move_cursor_right");
      static_cast<Action::Queue *>(action)->add_action(new Action::Transform::InsertNote(notes, current_grid_editor->note_cursor_x+1, Note()));
      static_cast<Action::Queue *>(action)->add_action(new Action::MoveCursorRight(current_grid_editor));
   }
   else if (action_name == "toggle_show_debug_data")
      action = new Action::ToggleShowDebugData(current_grid_editor);
   else if (action_name == "toggle_playback")
      action = new Action::TogglePlayback(&current_grid_editor->playback_control);
   else if (action_name == "reset_playback")
      action = new Action::ResetPlayback(current_grid_editor);
   else if (action_name == "save_grid")
      action = new Action::SaveGrid(&current_grid_editor->grid, "score_filename.fs");
   else if (action_name == "load_grid")
      action = new Action::LoadGrid(&current_grid_editor->grid, "score_filename.fs");
   else if (action_name == "camera_zoom_in")
      action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), current_grid_editor->place.scale.x + 0.1, 0.3);
   else if (action_name == "camera_zoom_default")
      action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), 1, 0.3);
   else if (action_name == "camera_zoom_out")
      action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), current_grid_editor->place.scale.x - 0.1, 0.3);
   else if (action_name == "move_cursor_left")
      action = new Action::MoveCursorLeft(current_grid_editor);
   else if (action_name == "move_cursor_down")
      action = new Action::MoveCursorDown(current_grid_editor);
   else if (action_name == "move_cursor_up")
      action = new Action::MoveCursorUp(current_grid_editor);
   else if (action_name == "move_cursor_right")
      action = new Action::MoveCursorRight(current_grid_editor);
   else if (action_name == "yank_measure_to_buffer")
   {
      action = new Action::Queue("yank_measure_to_buffer and set_reference_cursor");
      static_cast<Action::Queue *>(action)->add_action(new Action::YankMeasureToBuffer(&yank_measure_buffer, focused_measure));
      static_cast<Action::Queue *>(action)->add_action(new Action::SetReferenceCursor(&reference_cursor,
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y)
         );
   }
   else if (action_name == "paste_measure_from_buffer")
   {
      Measure::Base *measure_at_cursor = current_grid_editor->get_measure_at_cursor();
      if (measure_at_cursor && measure_at_cursor->get_type() == Measure::TYPE_IDENTIFIER_BASIC)
      {
         action = new Action::PasteMeasureFromBuffer(focused_measure, &yank_measure_buffer);
      }
      else
      {
         // a measure already exists here.  Delete it, create a _new_ basic measure, and then paste the contents into that measure
         Action::Queue *action_as_queue = new Action::Queue("stack: delete_measure, set_basic_measure, paste_measure_from_buffer_to_grid_coordinates");

         action_as_queue->add_action(new Action::DeleteMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y));
         action_as_queue->add_action(new Action::SetBasicMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y));
         action_as_queue->add_action(new Action::PasteMeasureFromBufferToGridCoordinates(&yank_measure_buffer,
               &current_grid_editor->grid,
               current_grid_editor->measure_cursor_x,
               current_grid_editor->measure_cursor_y)
            );

         action = action_as_queue;
      }
   }
   else if (action_name == "toggle_edit_mode_target")
      action = new Action::ToggleEditModeTarget(current_grid_editor);
   else if (action_name == "set_reference_by_coordinate_measure")
      action = new Action::SetReferenceByCoordinateMeasure(
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y,
            reference_cursor.get_grid(), reference_cursor.get_x(), reference_cursor.get_y());
   else if (action_name == "set_reference_by_id_measure")
   {
      action = new Action::SetReferenceByIDMeasure(
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y,
            measure_at_reference_cursor ? measure_at_reference_cursor->get_id() : Measure::NO_RECORD
         );
   }
   else if (action_name == "set_reference_cursor")
      action = new Action::SetReferenceCursor(&reference_cursor,
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_name == "set_basic_measure")
      action = new Action::SetBasicMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_name == "set_stack_measure")
      action = new Action::SetStackMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_name == "insert_column")
      action = new Action::InsertColumn(&current_grid_editor->grid, current_grid_editor->measure_cursor_x);
   else if (action_name == "delete_measure")
      action = new Action::DeleteMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_name == "delete_grid_column")
      action = new Action::DeleteGridColumn(&current_grid_editor->grid, current_grid_editor->measure_cursor_x);
   else if (action_name == "insert_staff")
      action = new Action::InsertStaff(&current_grid_editor->grid, current_grid_editor->measure_cursor_y);
   else if (action_name == "delete_staff")
      action = new Action::DeleteStaff(&current_grid_editor->grid, current_grid_editor->measure_cursor_y);
   else if (action_name == "append_column_to_grid")
      action = new Action::AppendColumnToGrid(&current_grid_editor->grid);
   else if (action_name == "append_staff")
      action = new Action::AppendStaff(&current_grid_editor->grid);
   else if (action_name == "set_time_signature_numerator_2")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 2);
   else if (action_name == "set_time_signature_numerator_3")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 3);
   else if (action_name == "set_time_signature_numerator_4")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 4);
   else if (action_name == "set_time_signature_numerator_5")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 5);

   return action;
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

            Action::SetNormalMode return_to_normal_mode(current_grid_editor, command_bar);
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

         Action::SetNormalMode return_to_normal_mode(current_grid_editor, command_bar);
         return_to_normal_mode.execute();
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




