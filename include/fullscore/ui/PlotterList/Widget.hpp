#pragma once


#include <allegro_flare/gui/widget.h>
#include <fullscore/models/lists/PlotterList.hpp>
#include <allegro_flare/keyboard_command_mapper.h>


namespace Plotter { class Base; }


namespace UI::PlotterList
{
   class Widget : public UIWidget
   {
   private:
      int cursor_pos;
      ::PlotterList *plotter_list;
      KeyboardCommandMapper keyboard_command_mapper;

      void _set_keyboard_mappings();

   public:
      Widget(UIWidget *parent, ::PlotterList *plotter_list, float width=300, float height=400);
      ~Widget();

      void set_plotter_list(::PlotterList *plotter_list);

      void move_cursor_up();
      void move_cursor_down();
      Plotter::Base *get_current_selected_plotter();

      std::vector<std::string> get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt);

      virtual void on_draw();
   };
}


