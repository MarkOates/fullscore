

#include <fullscore/UI/GridEditor/ActionFactory.hpp>

#include <fullscore/UI/GridEditor/Actions.hpp>
#include <fullscore/actions/QueueAction.h>

#include <allegro_flare/framework.h>
#include <fullscore/actions/transforms/AddDotToNote.h>
#include <fullscore/actions/transforms/AppendNote.h>
#include <fullscore/actions/transforms/Ascend.h>
#include <fullscore/actions/transforms/ClearMeasure.h>
#include <fullscore/actions/transforms/Descend.h>
#include <fullscore/actions/transforms/DoubleDuration.h>
#include <fullscore/actions/transforms/EraseNote.h>
#include <fullscore/actions/transforms/HalfDuration.h>
#include <fullscore/actions/transforms/InsertNote.h>
#include <fullscore/actions/transforms/InsertNoteAfter.h>
#include <fullscore/actions/transforms/Invert.h>
#include <fullscore/actions/transforms/Octatonic1.h>
#include <fullscore/actions/transforms/RemoveDot.h>
#include <fullscore/actions/transforms/Retrograde.h>
#include <fullscore/actions/transforms/SplitNote.h>
#include <fullscore/actions/transforms/ToggleRest.h>
#include <fullscore/actions/transforms/TransposeUp.h>
#include <fullscore/actions/transforms/TransposeDown.h>

#include <fullscore/UI/GridEditor/Actions/SetTimeSignatureNumerator.hpp>

#include <fullscore/UI/GridEditor/Actions/CreateNewGridEditor.hpp>
#include <fullscore/UI/GridEditor/Actions/PasteMeasureFromBuffer.hpp>
#include <fullscore/UI/GridEditor/Actions/PlotPlotterList.hpp>
#include <fullscore/UI/GridEditor/Actions/ResetPlayback.hpp>
#include <fullscore/UI/GridEditor/Actions/SetCurrentGridEditor.hpp>
#include <fullscore/UI/GridEditor/Actions/StartMotion.hpp>
#include <fullscore/UI/GridEditor/Actions/TogglePlayback.hpp>
#include <fullscore/UI/GridEditor/Actions/YankGridMeasureToBuffer.hpp>

#include <fullscore/UI/GridEditor/Actions/AppendStaff.hpp>
#include <fullscore/UI/GridEditor/Actions/CreateFloatingMeasure.hpp>
#include <fullscore/UI/GridEditor/Actions/DeleteFloatingMeasure.hpp>
#include <fullscore/UI/GridEditor/Actions/DeleteStaff.hpp>
#include <fullscore/UI/GridEditor/Actions/InsertStaff.hpp>
#include <fullscore/UI/GridEditor/Actions/LoadGrid.hpp>
#include <fullscore/UI/GridEditor/Actions/MoveCursorDown.hpp>
#include <fullscore/UI/GridEditor/Actions/MoveCursorLeft.hpp>
#include <fullscore/UI/GridEditor/Actions/MoveCursorRight.hpp>
#include <fullscore/UI/GridEditor/Actions/MoveCursorUp.hpp>
#include <fullscore/UI/GridEditor/Actions/MoveFloatingMeasureCursorRight.hpp>
#include <fullscore/UI/GridEditor/Actions/MoveFloatingMeasureCursorLeft.hpp>
#include <fullscore/UI/GridEditor/Actions/ResetFloatingMeasureCursor.hpp>
#include <fullscore/UI/GridEditor/Actions/SaveGrid.hpp>
#include <fullscore/UI/GridEditor/Actions/SetCameraTarget.hpp>
#include <fullscore/UI/GridEditor/Actions/SetCommandMode.hpp>
#include <fullscore/UI/GridEditor/Actions/SetMode.hpp>
#include <fullscore/UI/GridEditor/Actions/SetNormalMode.hpp>
#include <fullscore/UI/GridEditor/Actions/SetScoreZoom.hpp>
#include <fullscore/UI/GridEditor/Actions/ToggleEditModeTarget.hpp>
#include <fullscore/UI/GridEditor/Actions/ToggleShowDebugData.hpp>

#include <fullscore/models/Measure.h>
#include <fullscore/Action.h>
#include <fullscore/AppController.hpp>

// these next 3 includes are added to temporarily construct arguments for CreateFloatingMeasureAction
#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Staff.h>



namespace UI::GridEditor
{


Action::Base *ActionFactory::create_action(AppController *app_controller, Widget *widget, std::string action_name)
{
   if (!app_controller) throw std::runtime_error("Cannot create action with an nullptr app_controller");

   //
   // APP COMMANDS
   //

   Action::Base *action = nullptr;

   //if (action_name == "create_new_plotter_editor")
      //action = new Actions::CreateNewPlotterEditor(app_controller);
   if (action_name == "create_new_grid_editor")
      action = new Actions::CreateNewScoreEditor(app_controller);
   else if (action_name == "set_current_grid_editor")
      action = new Actions::SetCurrentUIGridEditor(app_controller, app_controller->get_next_grid_editor_widget());

   if (action) return action;


   //
   // SCORE EDITING COMMANDS
   //
   if (action_name == "move_camera_up")
      action = new Actions::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x, app_controller->follow_camera.target.position.y + 100);
   else if (action_name == "move_camera_down")
      action = new Actions::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x, app_controller->follow_camera.target.position.y - 100);
   else if (action_name == "move_camera_right")
      action = new Actions::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x - 100, app_controller->follow_camera.target.position.y);
   else if (action_name == "move_camera_left")
      action = new Actions::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x + 100, app_controller->follow_camera.target.position.y);

   if (action) return action;

   UI::GridEditor::Widget *current_grid_editor_widget = app_controller->current_grid_editor_widget;

   if (!current_grid_editor_widget) return nullptr;

   std::vector<Note> *notes = nullptr;
   Note *single_note = nullptr;
   Measure::Base *focused_measure = nullptr;

   if (current_grid_editor_widget->is_note_target_mode())
   {
      single_note = current_grid_editor_widget->get_note_at_cursor();
      focused_measure = current_grid_editor_widget->get_measure_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }
   if (current_grid_editor_widget->is_measure_target_mode())
   {
      focused_measure = current_grid_editor_widget->get_measure_at_cursor();
      if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   }

   if (action_name == "transpose_up")
   {
      if (current_grid_editor_widget->is_note_target_mode())
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
      if (current_grid_editor_widget->is_note_target_mode())
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
      if (current_grid_editor_widget->is_note_target_mode()) action = new Action::Transform::HalfDuration(single_note);
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
      if (current_grid_editor_widget->is_note_target_mode()) action = new Action::Transform::DoubleDuration(single_note);
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
      if (current_grid_editor_widget->is_note_target_mode()) action = new Action::Transform::ToggleRest(single_note);
      else
      {
         if (!notes) { std::cout << "cannot toggle_rest on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::ToggleRest(&note));
         return action_queue;
      }
   }
   else if (action_name == "invert")
   {
      if (current_grid_editor_widget->is_note_target_mode()) action = new Action::Transform::Invert(single_note);
      else
      {
         if (!notes) { std::cout << "cannot invert_note on nullptr notes" << std::endl; return nullptr; }
         Action::Queue *action_queue = new Action::Queue(action_name);
         for (auto &note : *notes) action_queue->add_action(new Action::Transform::Invert(&note));
         return action_queue;
      }
   }
   else if (action_name == "erase_note")
      action = new Action::Transform::EraseNote(notes, current_grid_editor_widget->note_cursor_x);
   else if (action_name == "ascend")
      action = new Action::Transform::Ascend(notes);
   else if (action_name == "descend")
      action = new Action::Transform::Descend(notes);
   else if (action_name == "add_dot_to_note")
      action = new Action::Transform::AddDotToNote(single_note);
   else if (action_name == Action::REMOVE_DOT_ACTION_IDENTIFIER)
      action = new Action::Transform::RemoveDot(single_note);
   //else if (action_identifier == Action::SET_COMMAND_MODE_ACTION_IDENTIFIER)
      //action = new Action::SetCommandMode(current_grid_editor, app_controller->command_bar);
   //else if (action_identifier == Action::SET_NORMAL_MODE_ACTION_IDENTIFIER)
      //action = new Action::SetNormalMode(current_grid_editor, app_controller->command_bar);
   else if (action_name == "split_note")
      action = new Action::Transform::SplitNote(notes);
   else if (action_name == "retrograde")
      action = new Action::Transform::Retrograde(notes);
   else if (action_name == "octatonic_1")
      action = new Action::Transform::Octatonic1(notes);
   else if (action_name == "insert_note")
      action = new Action::Transform::InsertNote(notes, current_grid_editor_widget->note_cursor_x, Note());
   else if (action_name == Action::INSERT_NOTE_AFTER_TRANSFORM_IDENTIFIER)
      action = new Action::Transform::InsertNoteAfter(notes, current_grid_editor_widget->note_cursor_x, Note());
   else if (action_name == "toggle_show_debug_data")
      action = new Actions::ToggleShowDebugData(current_grid_editor_widget);
   else if (action_name == "toggle_playback")
      action = new Actions::TogglePlayback(&current_grid_editor_widget->playback_control);
   else if (action_name == "reset_playback")
      action = new Actions::ResetPlayback(current_grid_editor_widget);
   else if (action_name == "reset_floating_measure_cursor")
   {
      Staff::Base *current_cursor_staff = current_grid_editor_widget->grid.get_staff(current_grid_editor_widget->grid_cursor_y);
      int current_staff_id = current_cursor_staff->get_id();
      int current_barline_num = current_grid_editor_widget->grid_cursor_x;
      action = new Actions::ResetFloatingMeasureCursor(&current_grid_editor_widget->floating_measure_cursor, current_staff_id, current_barline_num);
   }
   else if (action_name == "save_grid")
      action = new Actions::SaveGrid(&current_grid_editor_widget->grid, "score_filename.fs");
   else if (action_name == "load_grid")
      action = new Actions::LoadGrid(&current_grid_editor_widget->grid, "score_filename.fs");
   else if (action_name == "camera_zoom_in")
      action = new Actions::SetScoreZoom(current_grid_editor_widget, &Framework::motion(), current_grid_editor_widget->place.scale.x + 0.1, 0.3);
   else if (action_name == "camera_zoom_default")
      action = new Actions::SetScoreZoom(current_grid_editor_widget, &Framework::motion(), 1, 0.3);
   else if (action_name == "camera_zoom_out")
      action = new Actions::SetScoreZoom(current_grid_editor_widget, &Framework::motion(), current_grid_editor_widget->place.scale.x - 0.1, 0.3);
   else if (action_name == "move_cursor_left")
      action = new Actions::MoveCursorLeft(current_grid_editor_widget);
   else if (action_name == "move_cursor_down")
      action = new Actions::MoveCursorDown(current_grid_editor_widget);
   else if (action_name == Actions::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
      action = new Actions::MoveCursorUp(current_grid_editor_widget);
   else if (action_name == Actions::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER)
      action = new Actions::MoveCursorRight(current_grid_editor_widget);
   else if (action_name == Actions::MOVE_FLOATING_MEASURE_CURSOR_RIGHT_IDENTIFIER)
      action = new Actions::MoveFloatingMeasureCursorRight(&current_grid_editor_widget->floating_measure_cursor);
   else if (action_name == Actions::MOVE_FLOATING_MEASURE_CURSOR_LEFT_IDENTIFIER)
      action = new Actions::MoveFloatingMeasureCursorLeft(&current_grid_editor_widget->floating_measure_cursor);
   else if (action_name == Actions::INSERT_STAFF_ACTION_IDENTIFIER)
      action = new Actions::InsertStaff(&current_grid_editor_widget->grid, current_grid_editor_widget->grid_cursor_y);
   else if (action_name == Actions::DELETE_FLOATING_MEASURE_IDENTIFIER)
      action = new Actions::DeleteFloatingMeasure(current_grid_editor_widget->floating_measure_cursor.get_floating_measure_id());
   else if (action_name == Actions::DELETE_STAFF_ACTION_IDENTIFIER)
      action = new Actions::DeleteStaff(&current_grid_editor_widget->grid, current_grid_editor_widget->grid_cursor_y);
   else if (action_name == Actions::APPEND_STAFF_ACTION_IDENTIFIER)
      action = new Actions::AppendStaff(&current_grid_editor_widget->grid);
   else if (action_name == Actions::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER)
   {
      Staff::Base *current_cursor_staff = current_grid_editor_widget->grid.get_staff(current_grid_editor_widget->grid_cursor_y);
      int current_staff_id = current_cursor_staff->get_id();
      int current_barline_num = current_grid_editor_widget->grid_cursor_x;
      GridCoordinate grid_coordinate(current_staff_id, GridHorizontalCoordinate(current_barline_num, 0));
      Measure::Base *static_measure = new Measure::Basic({Note(0, {Duration::WHOLE})});

      action = new Actions::CreateFloatingMeasure(grid_coordinate, static_measure->get_id());
   }
   else if (action_name == "toggle_edit_mode_target")
      action = new Actions::ToggleEditModeTarget(current_grid_editor_widget);
   else if (action_name == "set_time_signature_numerator_2")
      action = new Actions::SetTimeSignatureNumerator(current_grid_editor_widget->grid.get_time_signature_ptr(current_grid_editor_widget->grid_cursor_x), 2);
   else if (action_name == "set_time_signature_numerator_3")
      action = new Actions::SetTimeSignatureNumerator(current_grid_editor_widget->grid.get_time_signature_ptr(current_grid_editor_widget->grid_cursor_x), 3);
   else if (action_name == "set_time_signature_numerator_4")
      action = new Actions::SetTimeSignatureNumerator(current_grid_editor_widget->grid.get_time_signature_ptr(current_grid_editor_widget->grid_cursor_x), 4);
   else if (action_name == "set_time_signature_numerator_5")
      action = new Actions::SetTimeSignatureNumerator(current_grid_editor_widget->grid.get_time_signature_ptr(current_grid_editor_widget->grid_cursor_x), 5);
   else if (action_name == Actions::YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER)
      action = new Actions::YankGridMeasureToBuffer(&app_controller->yank_measure_buffer, focused_measure);
   else if (action_name == "paste_measure_from_buffer")
      action = new Actions::PasteMeasureFromBuffer(current_grid_editor_widget->get_measure_at_cursor(), &app_controller->yank_measure_buffer);
   else if (action_name == Actions::PLOT_PLOTTER_LIST_ACTION_IDENTIFIER)
      action = new Actions::PlotPlotterList(app_controller->plotter_list);

   return action;
}


} // namespace UI::GridEditor


