


#include <fullscore/factories/action_factory.h>

#include <fullscore/actions/transforms/AddDotToNote.h>
#include <fullscore/actions/transforms/AppendNote.h>
#include <fullscore/actions/transforms/Ascend.h>
#include <fullscore/actions/transforms/ClearMeasure.h>
#include <fullscore/actions/transforms/Descend.h>
#include <fullscore/actions/transforms/DoubleDuration.h>
#include <fullscore/actions/transforms/EraseNote.h>
#include <fullscore/actions/transforms/HalfDuration.h>
#include <fullscore/actions/transforms/InsertNote.h>
#include <fullscore/actions/transforms/Invert.h>
#include <fullscore/actions/transforms/Octatonic1.h>
#include <fullscore/actions/transforms/RemoveDot.h>
#include <fullscore/actions/transforms/Retrograde.h>
#include <fullscore/actions/transforms/SplitNote.h>
#include <fullscore/actions/transforms/ToggleRest.h>
#include <fullscore/actions/transforms/TransposeUp.h>
#include <fullscore/actions/transforms/TransposeDown.h>
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
#include <fullscore/app_controller.h>



Action::Base *ActionFactory::create_action(AppController *app_controller, std::string action_identifier)
{
   if (!app_controller) throw std::runtime_error("Cannot create action with an nullptr app_controller");

   //
   // APP COMMANDS
   //

   Action::Base *action = nullptr;

   if (action_identifier == "create_new_grid_editor")
      action = new Action::CreateNewScoreEditor(app_controller);
   else if (action_identifier == "set_current_grid_editor")
      action = new Action::SetCurrentUIGridEditor(app_controller, get_next_grid_editor());
   else if (action_identifier == "move_camera_up")
      action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x, app_controller->follow_camera.target.position.y + 100);
   else if (action_identifier == "move_camera_down")
      action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x, app_controller->follow_camera.target.position.y - 100);
   else if (action_identifier == "move_camera_right")
      action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x - 100, app_controller->follow_camera.target.position.y);
   else if (action_identifier == "move_camera_left")
      action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x + 100, app_controller->follow_camera.target.position.y);

   if (action) return action;


   //
   // SCORE EDITING COMMANDS
   //

   if (!current_grid_editor) return nullptr;

   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   Measure::Base *focused_measure = nullptr;
   Measure::Base *measure_at_reference_cursor = nullptr;

   if (app_controller->reference_cursor.is_valid())
   {
      measure_at_reference_cursor = app_controller->reference_cursor.get_grid()->get_measure(app_controller->reference_cursor.get_x(), app_controller->reference_cursor.get_y());
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

   if (action_identifier == "transpose_up")
   {
      if (current_grid_editor->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::Transform::TransposeUp(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_up on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::Transform::TransposeUp(&note));
         return action_queue;
      }
   }
   else if (action_identifier == "transpose_down")
   {
      if (current_grid_editor->is_note_target_mode())
      {
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            action_queue->add_action(new Action::Transform::TransposeDown(single_note));
         return action_queue;
      }
      else
      {
         if (!notes) { std::cout << "cannot transpose_down on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (auto &note : *notes)
            for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               action_queue->add_action(new Action::Transform::TransposeDown(&note));
         return action_queue;
      }
   }
   else if (action_identifier == "half_duration")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::HalfDuration(single_note);
      else
      {
         if (!notes) { std::cout << "cannot half_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::HalfDuration(&note));
         return action_queue;
      }
   }
   else if (action_identifier == "double_duration")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::DoubleDuration(single_note);
      else
      {
         if (!notes) { std::cout << "cannot double_duration on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::DoubleDuration(&note));
         return action_queue;
      }
   }
   else if (action_identifier == "toggle_rest")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::ToggleRest(single_note);
      else
      {
         if (!notes) { std::cout << "cannot toggle_rest on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::ToggleRest(&note));
         return action_queue;
      }
   }
   else if (action_identifier == "invert")
   {
      if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::Invert(single_note);
      else
      {
         if (!notes) { std::cout << "cannot invert_note on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_identifier);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::Invert(&note));
         return action_queue;
      }
   }
   else if (action_identifier == "erase_note")
      action = new Action::Transform::EraseNote(notes, current_grid_editor->note_cursor_x);
   else if (action_identifier == "ascend")
      action = new Action::Transform::Ascend(notes);
   else if (action_identifier == "descend")
      action = new Action::Transform::Descend(notes);
   else if (action_identifier == "add_dot_to_note")
      action = new Action::Transform::AddDotToNote(single_note);
   else if (action_identifier == "remove_dot")
      action = new Action::Transform::RemoveDot(single_note);
   else if (action_identifier == "set_command_mode")
      action = new Action::SetCommandMode(current_grid_editor, command_bar);
   else if (action_identifier == "set_normal_mode")
      action = new Action::SetNormalMode(current_grid_editor, command_bar);
   else if (action_identifier == "split_note")
      action = new Action::Transform::SplitNote(notes);
   else if (action_identifier == "retrograde")
      action = new Action::Transform::Retrograde(notes);
   else if (action_identifier == "octatonic_1_transform")
      action = new Action::Transform::Octatonic1(notes);
   else if (action_identifier == "insert_note")
      action = new Action::Transform::InsertNote(notes, current_grid_editor->note_cursor_x, Note());
   else if (action_identifier == "insert_note_after")
   {
      action = new Action::Queue("insert_note_after: insert_note and move_cursor_right");
      static_cast<Action::Queue *>(action)->add_action(new Action::Transform::InsertNote(notes, current_grid_editor->note_cursor_x+1, Note()));
      static_cast<Action::Queue *>(action)->add_action(new Action::MoveCursorRight(current_grid_editor));
   }
   else if (action_identifier == "toggle_show_debug_data")
      action = new Action::ToggleShowDebugData(current_grid_editor);
   else if (action_identifier == "toggle_playback")
      action = new Action::TogglePlayback(&current_grid_editor->playback_control);
   else if (action_identifier == "reset_playback")
      action = new Action::ResetPlayback(current_grid_editor);
   else if (action_identifier == "save_grid")
      action = new Action::SaveGrid(&current_grid_editor->grid, "score_filename.fs");
   else if (action_identifier == "load_grid")
      action = new Action::LoadGrid(&current_grid_editor->grid, "score_filename.fs");
   else if (action_identifier == "camera_zoom_in")
      action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), current_grid_editor->place.scale.x + 0.1, 0.3);
   else if (action_identifier == "camera_zoom_default")
      action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), 1, 0.3);
   else if (action_identifier == "camera_zoom_out")
      action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), current_grid_editor->place.scale.x - 0.1, 0.3);
   else if (action_identifier == "move_cursor_left")
      action = new Action::MoveCursorLeft(current_grid_editor);
   else if (action_identifier == "move_cursor_down")
      action = new Action::MoveCursorDown(current_grid_editor);
   else if (action_identifier == "move_cursor_up")
      action = new Action::MoveCursorUp(current_grid_editor);
   else if (action_identifier == "move_cursor_right")
      action = new Action::MoveCursorRight(current_grid_editor);
   else if (action_identifier == "yank_measure_to_buffer")
   {
      action = new Action::Queue("yank_measure_to_buffer and set_reference_cursor");
      static_cast<Action::Queue *>(action)->add_action(new Action::YankMeasureToBuffer(&yank_measure_buffer, focused_measure));
      static_cast<Action::Queue *>(action)->add_action(new Action::SetReferenceCursor(&app_controller->reference_cursor,
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y)
         );
   }
   else if (action_identifier == "paste_measure_from_buffer")
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
   else if (action_identifier == "toggle_edit_mode_target")
      action = new Action::ToggleEditModeTarget(current_grid_editor);
   else if (action_identifier == "set_reference_by_coordinate_measure")
      action = new Action::SetReferenceByCoordinateMeasure(
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y,
            app_controller->reference_cursor.get_grid(), app_controller->reference_cursor.get_x(), app_controller->reference_cursor.get_y());
   else if (action_identifier == "set_reference_by_id_measure")
   {
      action = new Action::SetReferenceByIDMeasure(
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y,
            measure_at_reference_cursor ? measure_at_reference_cursor->get_id() : Measure::NO_RECORD
         );
   }
   else if (action_identifier == "set_reference_cursor")
      action = new Action::SetReferenceCursor(&app_controller->reference_cursor,
            &current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_identifier == "set_basic_measure")
      action = new Action::SetBasicMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_identifier == "set_stack_measure")
      action = new Action::SetStackMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_identifier == "insert_column")
      action = new Action::InsertColumn(&current_grid_editor->grid, current_grid_editor->measure_cursor_x);
   else if (action_identifier == "delete_measure")
      action = new Action::DeleteMeasure(&current_grid_editor->grid, current_grid_editor->measure_cursor_x, current_grid_editor->measure_cursor_y);
   else if (action_identifier == "delete_grid_column")
      action = new Action::DeleteGridColumn(&current_grid_editor->grid, current_grid_editor->measure_cursor_x);
   else if (action_identifier == "insert_staff")
      action = new Action::InsertStaff(&current_grid_editor->grid, current_grid_editor->measure_cursor_y);
   else if (action_identifier == "delete_staff")
      action = new Action::DeleteStaff(&current_grid_editor->grid, current_grid_editor->measure_cursor_y);
   else if (action_identifier == "append_column_to_grid")
      action = new Action::AppendColumnToGrid(&current_grid_editor->grid);
   else if (action_identifier == "append_staff")
      action = new Action::AppendStaff(&current_grid_editor->grid);
   else if (action_identifier == "set_time_signature_numerator_2")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 2);
   else if (action_identifier == "set_time_signature_numerator_3")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 3);
   else if (action_identifier == "set_time_signature_numerator_4")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 4);
   else if (action_identifier == "set_time_signature_numerator_5")
      action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->measure_cursor_x), 5);

   return action;
}



