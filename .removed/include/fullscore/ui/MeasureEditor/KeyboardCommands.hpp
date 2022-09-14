#pragma once


#include <allegro_flare/allegro_flare.h>
#include <allegro_flare/keyboard_command_mapper.h>


namespace UI::MeasureEditor
{
   class NoteModeKeyboardCommands : public KeyboardCommandMapper
   {
   public:
      NoteModeKeyboardCommands();
      ~NoteModeKeyboardCommands();

      void set_keyboard_commands();
   };


   class MeasureModeKeyboardCommands : public KeyboardCommandMapper
   {
   public:
      MeasureModeKeyboardCommands();
      ~MeasureModeKeyboardCommands();

      void set_keyboard_commands();
   };
}


