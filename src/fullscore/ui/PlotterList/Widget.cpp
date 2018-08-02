

#include <fullscore/UI/PlotterList/Widget.hpp>

#include <fullscore/UI/PlotterList/Actions.hpp>
#include <allegro_flare/gui/surface_areas/box.h>
#include <fullscore/models/plotters/Base.h>
#include <allegro_flare/framework.h>
#include <fullscore/UI/PlotterList/RenderComponents/ListItem.hpp>
#include <allegro5/allegro_primitives.h>


namespace UI::PlotterList
{


Widget::Widget(UIWidget *parent, ::PlotterList *plotter_list, float width, float height)
   : UIWidget(parent, "Widget", new UISurfaceAreaBox(0, 0, width, height))
   , cursor_pos(0)
   , plotter_list(plotter_list)
   , keyboard_command_mapper()
{
   place.align = vec2d(0, 0);
   place.position = vec2d(1600, 100);
   _set_keyboard_mappings();
}


Widget::~Widget()
{
}


void Widget::_set_keyboard_mappings()
{
   //                                  keycode,           shift, ctrl,  alt,   identifier
   keyboard_command_mapper.set_mapping(ALLEGRO_KEY_J,     false, false, false, {Actions::MOVE_CURSOR_UP_ACTION_IDENTIFIER});
   keyboard_command_mapper.set_mapping(ALLEGRO_KEY_K,     false, false, false, {Actions::MOVE_CURSOR_DOWN_ACTION_IDENTIFIER});
   keyboard_command_mapper.set_mapping(ALLEGRO_KEY_ENTER, false, false, false, {Actions::SELECT_PLOTTER_ACTION_IDENTIFIER});
}


void Widget::set_plotter_list(::PlotterList *plotter_list)
{
   this->plotter_list = plotter_list;
}


static void __move_cursor(int &cursor_pos, int delta, int list_size)
{
   if (delta == 0) return;
   if (list_size <= 0) return;

   cursor_pos = cursor_pos + delta;
   while (cursor_pos < 0) { cursor_pos += list_size; }
   cursor_pos = cursor_pos % list_size;
}


void Widget::move_cursor_up()
{
   if (!plotter_list || plotter_list->count() == 0) return;
   __move_cursor(cursor_pos, -1, plotter_list->count());
}


void Widget::move_cursor_down()
{
   if (!plotter_list || plotter_list->count() == 0) return;
   __move_cursor(cursor_pos, 1, plotter_list->count());
}


Plotter::Base *Widget::get_current_selected_plotter()
{
   if (!plotter_list || plotter_list->count() == 0) return nullptr;
   return plotter_list->get(cursor_pos);
}


std::vector<std::string> Widget::get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt)
{
   return keyboard_command_mapper.get_mapping(al_keycode, shift, ctrl, alt);
}


void Widget::on_draw()
{
   float width = surface_area->placement.size.x;
   float height = surface_area->placement.size.y;

   if (!plotter_list)
   {
      al_draw_filled_rectangle(0, 0, width, height, al_color_name("red"));
      // draw null list
      UIWidget::on_draw();
      return;
   }

   if (plotter_list->count() == 0)
   {
      al_draw_filled_rectangle(0, 0, width, height, al_color_name("blue"));
      // draw empty list
      UIWidget::on_draw();
      return;
   }

   placement2d placement(0, 0, 0, 0, 0, 1, 1, 0);

   ALLEGRO_FONT *text_font = Framework::font("plantin-mt-light.ttf 22");

   al_draw_filled_rectangle(0, 0, width, height, al_color_name("darkgray"));
   al_draw_text(text_font, al_color_name("white"), 10, 10, ALLEGRO_ALIGN_LEFT, "Plotters (plot with Shift+P)");

   placement.position += vec2d(0, 50);

   int item_num = 0;
   for (auto &plotter : plotter_list->get_list_ref())
   {
      fullscore::UI::PlotterList::RenderComponents::ListItem list_item(plotter, text_font, al_color_name("gray"), width);
      if (item_num == cursor_pos) list_item.set_state_hilighted();

      placement.start_transform();
      list_item.render();

      placement.restore_transform();
      placement.position += vec2d(0, list_item.get_height());
      item_num++;
   }
}


} // namespace UI::CommandBar


