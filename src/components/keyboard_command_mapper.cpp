


#include <fullscore/components/keyboard_command_mapper.h>



KeyboardCommandMapper::KeyboardCommandMapper()
{}



KeyboardCommandMapper::~KeyboardCommandMapper()
{}



bool KeyboardCommandMapper::set_mapping(int al_keycode, bool shift, bool ctrl, bool alt, std::string command_identifier)
{
   mapping[std::tuple<int, bool, bool, bool>(al_keycode, shift, ctrl, alt)] = command_identifier;
   return true;
}



std::string KeyboardCommandMapper::get_mapping(int al_keycode, bool shift, bool ctrl, bool alt)
{
   return mapping[std::tuple<int, bool, bool, bool>(al_keycode, shift, ctrl, alt)];
}



