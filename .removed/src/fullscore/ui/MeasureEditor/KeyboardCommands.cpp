

#include <fullscore/UI/MeasureEditor/KeyboardCommands.hpp>
#include <fullscore/UI/MeasureEditor/Actions.hpp>


namespace UI::MeasureEditor
{


NoteModeKeyboardCommands::NoteModeKeyboardCommands()
{
   set_keyboard_commands();
}


NoteModeKeyboardCommands::~NoteModeKeyboardCommands()
{
}


void NoteModeKeyboardCommands::set_keyboard_commands()
{
   set_mapping(ALLEGRO_KEY_SPACE,   false, false, false, {Actions::SAY_HELLO_ACTION_IDENTIFIER});

   // note mode commands
   set_mapping(ALLEGRO_KEY_TAB,      false, false, false, {Actions::TOGGLE_EDIT_MODE_ACTION_IDENTIFIER});

   set_mapping(ALLEGRO_KEY_H,        false, false, false, {Actions::MOVE_CURSOR_LEFT_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_L,        false, false, false, {Actions::MOVE_CURSOR_RIGHT_ACTION_IDENTIFIER});

   set_mapping(ALLEGRO_KEY_A,        false, false, false, {"insert_note_after"});
   set_mapping(ALLEGRO_KEY_X,        false, false, false, {"erase_note"});
   set_mapping(ALLEGRO_KEY_I,        false, false, false, {"insert_note"});
   set_mapping(ALLEGRO_KEY_COMMA,    false, false, false, {"remove_dot"});
   set_mapping(ALLEGRO_KEY_FULLSTOP, false, false, false, {"add_dot_to_note"});

   // ???
   set_mapping(ALLEGRO_KEY_F,         false, false, false, {"transpose_up"});
   set_mapping(ALLEGRO_KEY_D,         false, false, false, {"transpose_down"});
   set_mapping(ALLEGRO_KEY_S,         false,  true, false, {"split_note"});
   set_mapping(ALLEGRO_KEY_S,         false, false, false, {"half_duration"});
   set_mapping(ALLEGRO_KEY_G,         false, false, false, {"double_duration"});
   set_mapping(ALLEGRO_KEY_R,         false, false, false, {"toggle_rest"});
   set_mapping(ALLEGRO_KEY_N,         false, false, false, {"invert"});
   set_mapping(ALLEGRO_KEY_Z,         false, false, false, {"retrograde"});
}


///


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
   set_mapping(ALLEGRO_KEY_TAB,      false, false, false, {Actions::TOGGLE_EDIT_MODE_ACTION_IDENTIFIER});

   set_mapping(ALLEGRO_KEY_F,         false, false, false, {"transpose_up"});
   set_mapping(ALLEGRO_KEY_D,         false, false, false, {"transpose_down"});
   set_mapping(ALLEGRO_KEY_S,         false,  true, false, {"split_note"});
   set_mapping(ALLEGRO_KEY_S,         false, false, false, {"half_duration"});
   set_mapping(ALLEGRO_KEY_G,         false, false, false, {"double_duration"});
   set_mapping(ALLEGRO_KEY_R,         false, false, false, {"toggle_rest"});
   set_mapping(ALLEGRO_KEY_N,         false, false, false, {"invert"});
   set_mapping(ALLEGRO_KEY_Z,         false, false, false, {"retrograde"});
   set_mapping(ALLEGRO_KEY_F, false, true,  false, {"ascend"});
   set_mapping(ALLEGRO_KEY_D, false, true,  false, {"descend"});
   //set_mapping(ALLEGRO_KEY_X, false, false, false, {Actions::DELETE_FLOATING_MEASURE_IDENTIFIER});
}


} // namespace UI::MeasureEditor


