#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/UI/ComponentTemplate/KeyboardCommands.hpp>


namespace UI::ComponentTemplate
{
   class Widget : public UIWidget
   {
   public:
      KeyboardCommandMapper keyboard_commands;
      void _set_keyboard_mappings();

      Widget(UIWidget *parent);

      std::vector<std::string> get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt);
   };
}

