

#include <fullscore/UI/PlotterList/KeyboardCommands.hpp>
#include <fullscore/UI/PlotterList/Actions.hpp>


namespace UI::PlotterList
{


KeyboardCommands::KeyboardCommands()
{
   set_keyboard_commands();
}


KeyboardCommands::~KeyboardCommands()
{
}


void KeyboardCommands::set_keyboard_commands()
{
   set_mapping(ALLEGRO_KEY_J,     false, false, false, {Actions::MOVE_CURSOR_UP_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_K,     false, false, false, {Actions::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER});
   set_mapping(ALLEGRO_KEY_ENTER, false, false, false, {Actions::SELECT_PLOTTER_ACTION_IDENTIFIER});
}


}


