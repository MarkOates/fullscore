

#include <fullscore/UI/ComponentTemplate/KeyboardCommands.hpp>
#include <fullscore/UI/ComponentTemplate/Actions.hpp>


namespace UI::ComponentTemplate
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


} // namespace UI::ComponentTemplate


