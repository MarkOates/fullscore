

#include <fullscore/UI/GridEditor/KeyboardCommands.hpp>
#include <fullscore/UI/GridEditor/Actions.hpp>


namespace UI::GridEditor
{


NormalModeKeyboardCommands::NormalModeKeyboardCommands()
{
   set_keyboard_commands();
}


NormalModeKeyboardCommands::~NormalModeKeyboardCommands()
{
}


void NormalModeKeyboardCommands::set_keyboard_commands()
{
   //                                        keycode,               shift, ctrl,  alt,   identifier
   set_mapping(ALLEGRO_KEY_G,         false, false, false, {"double_duration"});
   set_mapping(ALLEGRO_KEY_R,         false, false, false, {"toggle_rest"});
   set_mapping(ALLEGRO_KEY_N,         false, false, false, {"invert"});
   set_mapping(ALLEGRO_KEY_Z,         false, false, false, {"retrograde"});
   set_mapping(ALLEGRO_KEY_H,         false, false, false, {Actions::MOVE_CURSOR_LEFT_ACTION_IDENTIFIER
                                                                                         ,Actions::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_J,         false, false, false, {Actions::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER
                                                                                         ,Actions::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_SEMICOLON, false, false, false, {Actions::SET_COMMAND_MODE_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_MINUS,     false, false, false, {"camera_zoom_out"});
   set_mapping(ALLEGRO_KEY_EQUALS,    false, false, false, {"camera_zoom_in"});
   set_mapping(ALLEGRO_KEY_UP,        false, false, false, {"move_camera_up"});
   set_mapping(ALLEGRO_KEY_DOWN,      false, false, false, {"move_camera_down"});
   set_mapping(ALLEGRO_KEY_RIGHT,     false, false, false, {"move_camera_right"});
   set_mapping(ALLEGRO_KEY_LEFT,      false, false, false, {"move_camera_left"});
   set_mapping(ALLEGRO_KEY_TAB,       false, false, false, {Actions::TOGGLE_EDIT_MODE_TARGET_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_F2,        false, false, false, {Actions::TOGGLE_SHOW_DEBUG_DATA_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_SPACE,     false, false, false, {Actions::TOGGLE_PLAYBACK_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_4,         false, false, false, {"set_time_signature_numerator_4"});
   set_mapping(ALLEGRO_KEY_5,         false, false, false, {"set_time_signature_numerator_5"});
   set_mapping(ALLEGRO_KEY_Y,         false, false, false, {Actions::YANK_GRID_MEASURE_TO_BUFFER_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_P,         false, false, false, {Actions::PASTE_MEASURE_FROM_BUFFER_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_O,         false, false, false, {"octatonic_1"});
   set_mapping(ALLEGRO_KEY_2,         false, false, false, {"set_time_signature_numerator_2"});
   set_mapping(ALLEGRO_KEY_K,         false, false, false, {Actions::MOVE_CURSOR_UP_ACTION_IDENTIFIER
                                                                                         ,Actions::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_L,         false, false, false, {Actions::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER
                                                                                         ,Actions::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_W,         false, false, false, {Actions::MOVE_FLOATING_MEASURE_CURSOR_RIGHT_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_B,         true,  false, false, {Actions::MOVE_FLOATING_MEASURE_CURSOR_LEFT_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_S,         false, false, false, {"half_duration"});
   set_mapping(ALLEGRO_KEY_3,         false, false, false, {"set_time_signature_numerator_3"});
   set_mapping(ALLEGRO_KEY_F,         false, false, false, {"transpose_up"});
   set_mapping(ALLEGRO_KEY_D,         false, false, false, {"transpose_down"});
   set_mapping(ALLEGRO_KEY_S,         false,  true, false, {"split_note"});
   set_mapping(ALLEGRO_KEY_7,         true,  false, false, {"set_reference_by_id_measure"});
   set_mapping(ALLEGRO_KEY_EQUALS,    true,  false, false, {"camera_zoom_default"});
   set_mapping(ALLEGRO_KEY_M,         false, false, false, {Actions::CREATE_FLOATING_MEASURE_ACTION_IDENTIFIER
                                                                                         ,Actions::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_3,         true,  false, false, {"set_stack_measure"});



   // likely to be non-grid_editor actions
   set_mapping(ALLEGRO_KEY_Q,         false, false, false, {Actions::RESET_PLAYBACK_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_F7,        false, false, false, {Actions::SAVE_GRID_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_F8,        false, false, false, {Actions::LOAD_GRID_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_N,         false,  true, false, {"create_new_grid_editor"});
   set_mapping(ALLEGRO_KEY_X,         false,  true, false, {"set_current_grid_editor"});
   set_mapping(ALLEGRO_KEY_C,         false, false, false, {Actions::RESET_FLOATING_MEASURE_CURSOR_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_P,         true,  false, false, {Actions::PLOT_PLOTTER_LIST_ACTION_IDENTIFIER});
}


////


NoteModeKeyboardCommands::NoteModeKeyboardCommands()
{
   set_keyboard_commands();
}


NoteModeKeyboardCommands::~NoteModeKeyboardCommands()
{
}


void NoteModeKeyboardCommands::set_keyboard_commands()
{
   // note mode commands
   set_mapping(ALLEGRO_KEY_A,        false, false, false, {"insert_note_after"});
   set_mapping(ALLEGRO_KEY_X,        false, false, false, {"erase_note"});
   set_mapping(ALLEGRO_KEY_I,        false, false, false, {"insert_note"});
   set_mapping(ALLEGRO_KEY_COMMA,    false, false, false, {"remove_dot"});
   set_mapping(ALLEGRO_KEY_FULLSTOP, false, false, false, {"add_dot_to_note"});
}


////


MeasureModeKeyboardCommands::MeasureModeKeyboardCommands()
{
   set_keyboard_commands();
}


MeasureModeKeyboardCommands::~MeasureModeKeyboardCommands()
{
}


void MeasureModeKeyboardCommands::set_keyboard_commands()
{
   // measure mode commands
   set_mapping(ALLEGRO_KEY_F, false, true,  false, {"ascend"});
   set_mapping(ALLEGRO_KEY_D, false, true,  false, {"descend"});
   set_mapping(ALLEGRO_KEY_X, false, false, false, {Actions::DELETE_FLOATING_MEASURE_IDENTIFIER});
}


}


