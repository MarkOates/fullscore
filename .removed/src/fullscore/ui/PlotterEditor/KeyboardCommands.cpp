

#include <fullscore/UI/PlotterEditor/KeyboardCommands.hpp>
#include <fullscore/UI/PlotterEditor/Actions.hpp>


namespace UI::PlotterEditor
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
   set_mapping(ALLEGRO_KEY_H, false, false, false, {Actions::SAY_HELLO_ACTION_IDENTIFIER});
}


} // namespace UI::PlotterEditor


