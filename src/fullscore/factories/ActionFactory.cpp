


#include <fullscore/factories/ActionFactory.h>

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
#include <fullscore/actions/AppendStaffAction.h>
#include <fullscore/actions/CreateFloatingMeasureAction.h>
#include <fullscore/actions/CreateNewGridEditorAction.h>
#include <fullscore/actions/DeleteFloatingMeasureAction.h>
#include <fullscore/actions/DeleteStaffAction.h>
#include <fullscore/actions/InsertStaffAction.h>
#include <fullscore/actions/LoadGridAction.h>
#include <fullscore/actions/MoveCursorDownAction.h>
#include <fullscore/actions/MoveCursorLeftAction.h>
#include <fullscore/actions/MoveCursorRightAction.h>
#include <fullscore/actions/MoveCursorUpAction.h>
#include <fullscore/actions/MoveFloatingMeasureCursorRightAction.h>
#include <fullscore/actions/MoveFloatingMeasureCursorLeftAction.h>
#include <fullscore/actions/PasteMeasureFromBufferAction.h>
#include <fullscore/actions/PlotPlotterListAction.hpp>
#include <fullscore/actions/QueueAction.h>
#include <fullscore/actions/ResetFloatingMeasureCursorAction.h>
#include <fullscore/actions/ResetPlaybackAction.h>
#include <fullscore/actions/SaveGridAction.h>
#include <fullscore/actions/SetCameraTargetAction.h>
#include <fullscore/actions/SetCommandModeAction.h>
#include <fullscore/actions/SetCurrentGridEditorAction.h>
#include <fullscore/actions/SetModeAction.h>
#include <fullscore/actions/SetNormalModeAction.h>
#include <fullscore/actions/SetScoreZoomAction.h>
#include <fullscore/actions/SetTimeSignatureNumeratorAction.h>
#include <fullscore/actions/StartMotionAction.h>
#include <fullscore/actions/ToggleEditModeTargetAction.h>
#include <fullscore/actions/TogglePlaybackAction.h>
#include <fullscore/actions/ToggleShowDebugDataAction.h>
#include <fullscore/actions/YankGridMeasureToBufferAction.h>
#include <fullscore/models/Measure.h>
#include <fullscore/Action.h>
#include <fullscore/AppController.hpp>

// these next 3 includes are added to temporarily construct arguments for CreateFloatingMeasureAction
#include <fullscore/models/staves/Instrument.h>
#include <fullscore/models/Staff.h>



Action::Base *ActionFactory::create_action(AppController *app_controller, std::string action_identifier)
{
   //if (!app_controller) throw std::runtime_error("Cannot create action with an nullptr app_controller");

   ////
   //// APP COMMANDS
   ////

   //Action::Base *action = nullptr;

   //if (action_identifier == "create_new_grid_editor")
      //action = new Action::CreateNewScoreEditor(app_controller);
   //else if (action_identifier == "set_current_grid_editor")
      //throw std::runtime_error("no loger using 'grid_editor'");
      ////action = new Action::SetCurrentUIGridEditor(app_controller, app_controller->get_next_grid_editor());
   //else if (action_identifier == "move_camera_up")
      //action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x, app_controller->follow_camera.target.position.y + 100);
   //else if (action_identifier == "move_camera_down")
      //action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x, app_controller->follow_camera.target.position.y - 100);
   //else if (action_identifier == "move_camera_right")
      //action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x - 100, app_controller->follow_camera.target.position.y);
   //else if (action_identifier == "move_camera_left")
      //action = new Action::SetCameraTarget(&app_controller->follow_camera, app_controller->follow_camera.target.position.x + 100, app_controller->follow_camera.target.position.y);

   //if (action) return action;


   ////
   //// SCORE EDITING COMMANDS
   ////
   //UIGridEditor *current_grid_editor = app_controller->current_grid_editor;

   //if (!current_grid_editor) return nullptr;

   //std::vector<Note> *notes = nullptr;
   //Note *single_note = nullptr;
   //Measure::Base *focused_measure = nullptr;

   //if (current_grid_editor->is_note_target_mode())
   //{
      //single_note = current_grid_editor->get_note_at_cursor();
      //focused_measure = current_grid_editor->get_measure_at_cursor();
      //if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   //}
   //if (current_grid_editor->is_measure_target_mode())
   //{
      //focused_measure = current_grid_editor->get_measure_at_cursor();
      //if (focused_measure && focused_measure->get_notes_pointer()) notes = focused_measure->get_notes_pointer();
   //}

   //if (action_identifier == "transpose_up")
   //{
      //if (current_grid_editor->is_note_target_mode())
      //{
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            //action_queue->add_action(new Action::Transform::TransposeUp(single_note));
         //return action_queue;
      //}
      //else
      //{
         //if (!notes) { std::cout << "cannot transpose_up on nullptr notes" << std::endl; return nullptr; }
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (auto &note : *notes)
            //for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               //action_queue->add_action(new Action::Transform::TransposeUp(&note));
         //return action_queue;
      //}
   //}
   //else if (action_identifier == "transpose_down")
   //{
      //if (current_grid_editor->is_note_target_mode())
      //{
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
            //action_queue->add_action(new Action::Transform::TransposeDown(single_note));
         //return action_queue;
      //}
      //else
      //{
         //if (!notes) { std::cout << "cannot transpose_down on nullptr notes" << std::endl; return nullptr; }
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (auto &note : *notes)
            //for (unsigned i=0; i<(Framework::key_shift ? 7 : 1); i++)
               //action_queue->add_action(new Action::Transform::TransposeDown(&note));
         //return action_queue;
      //}
   //}
   //else if (action_identifier == "half_duration")
   //{
      //if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::HalfDuration(single_note);
      //else
      //{
         //if (!notes) { std::cout << "cannot half_duration on nullptr notes" << std::endl; return nullptr; }
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (auto &note : *notes) action_queue->add_action(new Action::Transform::HalfDuration(&note));
         //return action_queue;
      //}
   //}
   //else if (action_identifier == "double_duration")
   //{
      //if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::DoubleDuration(single_note);
      //else
      //{
         //if (!notes) { std::cout << "cannot double_duration on nullptr notes" << std::endl; return nullptr; }
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (auto &note : *notes) action_queue->add_action(new Action::Transform::DoubleDuration(&note));
         //return action_queue;
      //}
   //}
   //else if (action_identifier == "toggle_rest")
   //{
      //if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::ToggleRest(single_note);
      //else
      //{
         //if (!notes) { std::cout << "cannot toggle_rest on nullptr notes" << std::endl; return nullptr; }
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (auto &note : *notes) action_queue->add_action(new Action::Transform::ToggleRest(&note));
         //return action_queue;
      //}
   //}
   //else if (action_identifier == "invert")
   //{
      //if (current_grid_editor->is_note_target_mode()) action = new Action::Transform::Invert(single_note);
      //else
      //{
         //if (!notes) { std::cout << "cannot invert_note on nullptr notes" << std::endl; return nullptr; }
         //Action::Queue *action_queue = new Action::Queue(action_identifier);
         //for (auto &note : *notes) action_queue->add_action(new Action::Transform::Invert(&note));
         //return action_queue;
      //}
   //}
   //else if (action_identifier == "erase_note")
      //action = new Action::Transform::EraseNote(notes, current_grid_editor->note_cursor_x);
   //else if (action_identifier == "ascend")
      //action = new Action::Transform::Ascend(notes);
   //else if (action_identifier == "descend")
      //action = new Action::Transform::Descend(notes);
   //else if (action_identifier == "add_dot_to_note")
      //action = new Action::Transform::AddDotToNote(single_note);
   //else if (action_identifier == Action::REMOVE_DOT_ACTION_IDENTIFIER)
      //action = new Action::Transform::RemoveDot(single_note);
   ////else if (action_identifier == Action::SET_COMMAND_MODE_ACTION_IDENTIFIER)
      ////action = new Action::SetCommandMode(current_grid_editor, app_controller->command_bar);
   ////else if (action_identifier == Action::SET_NORMAL_MODE_ACTION_IDENTIFIER)
      ////action = new Action::SetNormalMode(current_grid_editor, app_controller->command_bar);
   //else if (action_identifier == "split_note")
      //action = new Action::Transform::SplitNote(notes);
   //else if (action_identifier == "retrograde")
      //action = new Action::Transform::Retrograde(notes);
   //else if (action_identifier == "octatonic_1")
      //action = new Action::Transform::Octatonic1(notes);
   //else if (action_identifier == "insert_note")
      //action = new Action::Transform::InsertNote(notes, current_grid_editor->note_cursor_x, Note());
   //else if (action_identifier == Action::INSERT_NOTE_AFTER_TRANSFORM_IDENTIFIER)
      //action = new Action::Transform::InsertNoteAfter(notes, current_grid_editor->note_cursor_x, Note());
   //else if (action_identifier == "toggle_show_debug_data")
      //action = new Action::ToggleShowDebugData(current_grid_editor);
   //else if (action_identifier == "toggle_playback")
      //action = new Action::TogglePlayback(&current_grid_editor->playback_control);
   //else if (action_identifier == "reset_playback")
      //action = new Action::ResetPlayback(current_grid_editor);
   //else if (action_identifier == "reset_floating_measure_cursor")
   //{
      //Staff::Base *current_cursor_staff = current_grid_editor->grid.get_staff(current_grid_editor->grid_cursor_y);
      //int current_staff_id = current_cursor_staff->get_id();
      //int current_barline_num = current_grid_editor->grid_cursor_x;
      //action = new Action::ResetFloatingMeasureCursor(&current_grid_editor->floating_measure_cursor, current_staff_id, current_barline_num);
   //}
   //else if (action_identifier == "save_grid")
      //action = new Action::SaveGrid(&current_grid_editor->grid, "score_filename.fs");
   //else if (action_identifier == "load_grid")
      //action = new Action::LoadGrid(&current_grid_editor->grid, "score_filename.fs");
   //else if (action_identifier == "camera_zoom_in")
      //action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), current_grid_editor->place.scale.x + 0.1, 0.3);
   //else if (action_identifier == "camera_zoom_default")
      //action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), 1, 0.3);
   //else if (action_identifier == "camera_zoom_out")
      //action = new Action::SetScoreZoom(current_grid_editor, &Framework::motion(), current_grid_editor->place.scale.x - 0.1, 0.3);
   //else if (action_identifier == "move_cursor_left")
      //action = new Action::MoveCursorLeft(current_grid_editor);
   //else if (action_identifier == "move_cursor_down")
      //action = new Action::MoveCursorDown(current_grid_editor);
   //else if (action_identifier == Action::MOVE_CURSOR_UP_ACTION_IDENTIFIER)
      //action = new Action::MoveCursorUp(current_grid_editor);
   //else if (action_identifier == Action::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER)
      //action = new Action::MoveCursorRight(current_grid_editor);
   //else if (action_identifier == Action::MOVE_FLOATING_MEASURE_CURSOR_RIGHT_IDENTIFIER)
      //action = new Action::MoveFloatingMeasureCursorRight(&current_grid_editor->floating_measure_cursor);
   //else if (action_identifier == Action::MOVE_FLOATING_MEASURE_CURSOR_LEFT_IDENTIFIER)
      //action = new Action::MoveFloatingMeasureCursorLeft(&current_grid_editor->floating_measure_cursor);
   //else if (action_identifier == Action::INSERT_STAFF_ACTION_IDENTIFIER)
      //action = new Action::InsertStaff(&current_grid_editor->grid, current_grid_editor->grid_cursor_y);
   //else if (action_identifier == Action::DELETE_FLOATING_MEASURE_IDENTIFIER)
      //action = new Action::DeleteFloatingMeasure(current_grid_editor->floating_measure_cursor.get_floating_measure_id());
   //else if (action_identifier == Action::DELETE_STAFF_ACTION_IDENTIFIER)
      //action = new Action::DeleteStaff(&current_grid_editor->grid, current_grid_editor->grid_cursor_y);
   //else if (action_identifier == Action::APPEND_STAFF_ACTION_IDENTIFIER)
      //action = new Action::AppendStaff(&current_grid_editor->grid);
   //else if (action_identifier == Action::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER)
   //{
      //Staff::Base *current_cursor_staff = current_grid_editor->grid.get_staff(current_grid_editor->grid_cursor_y);
      //int current_staff_id = current_cursor_staff->get_id();
      //int current_barline_num = current_grid_editor->grid_cursor_x;
      //GridCoordinate grid_coordinate(current_staff_id, GridHorizontalCoordinate(current_barline_num, 0));
      //Measure::Base *static_measure = new Measure::Basic({Note(0, {Duration::WHOLE})});

      //action = new Action::CreateFloatingMeasure(grid_coordinate, static_measure->get_id());
   //}
   //else if (action_identifier == "toggle_edit_mode_target")
      //action = new Action::ToggleEditModeTarget(current_grid_editor);
   //else if (action_identifier == "set_time_signature_numerator_2")
      //action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->grid_cursor_x), 2);
   //else if (action_identifier == "set_time_signature_numerator_3")
      //action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->grid_cursor_x), 3);
   //else if (action_identifier == "set_time_signature_numerator_4")
      //action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->grid_cursor_x), 4);
   //else if (action_identifier == "set_time_signature_numerator_5")
      //action = new Action::SetTimeSignatureNumerator(current_grid_editor->grid.get_time_signature_ptr(current_grid_editor->grid_cursor_x), 5);
   //else if (action_identifier == Action::YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER)
      //action = new Action::YankGridMeasureToBuffer(&app_controller->yank_measure_buffer, focused_measure);
   //else if (action_identifier == "paste_measure_from_buffer")
      //action = new Action::PasteMeasureFromBuffer(current_grid_editor->get_measure_at_cursor(), &app_controller->yank_measure_buffer);
   //else if (action_identifier == Action::PLOT_PLOTTER_LIST_ACTION_IDENTIFIER)
      //action = new Action::PlotPlotterList(app_controller->plotter_list);

   //return action;
   throw std::runtime_error("no longer using ActionFactory");
   return nullptr;
}


