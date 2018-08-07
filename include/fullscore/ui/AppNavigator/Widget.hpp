#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/UI/AppNavigator/KeyboardCommands.hpp>


namespace UI::AppNavigator::RenderComponents { class Widget; }


namespace UI::AppNavigator
{
   class Widget : public UIWidget
   {
   private:
      RenderComponents::Widget *render_component;
      KeyboardCommandMapper keyboard_command_mapper;

   public:
      Widget(UIWidget *parent, RenderComponents::Widget *render_component);
      ~Widget();

      std::vector<std::string> get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt);

      virtual void on_draw() override;
   };
}


