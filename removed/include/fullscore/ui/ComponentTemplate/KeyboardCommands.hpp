#pragma once


#include <allegro_flare/allegro_flare.h>
#include <allegro_flare/keyboard_command_mapper.h>


namespace UI::ComponentTemplate
{
   class KeyboardCommands : public KeyboardCommandMapper
   {
   public:
      KeyboardCommands();
      ~KeyboardCommands();

      void set_keyboard_commands();
   };
}


