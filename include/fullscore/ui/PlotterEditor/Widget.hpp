#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/ui/PlotterEditor/KeyboardCommands.hpp>


namespace Plotter { class Base; }


namespace UI::PlotterEditor
{
   class Widget : public UIWidget
   {
   private:
      Plotter::Base *plotter;
      KeyboardCommandMapper keyboard_command_mapper;

   public:
      Widget(UIWidget *parent, Plotter::Base *plotter);
      ~Widget();

      Plotter::Base *get_plotter();
      std::vector<std::string> get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt);

      virtual void on_draw() override;
   };
}


