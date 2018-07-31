

#include <fullscore/widgets/PlotterListWidget.hpp>

#include <allegro_flare/gui/surface_areas/box.h>
#include <allegro_flare/framework.h>
#include <fullscore/ui/PlotterListItemRenderComponent.hpp>
#include <allegro5/allegro_primitives.h>


PlotterListWidget::PlotterListWidget(UIWidget *parent, PlotterList *plotter_list, float width, float height)
   : UIWidget(parent, "PlotterListWidget", new UISurfaceAreaBox(0, 0, width, height))
   , cursor_pos(0)
   , plotter_list(plotter_list)
{
   place.align = vec2d(0, 0);
   place.position = vec2d(1600, 100);
}


PlotterListWidget::~PlotterListWidget()
{
}


void PlotterListWidget::set_plotter_list(PlotterList *plotter_list)
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


void PlotterListWidget::move_cursor_up()
{
   if (!plotter_list || plotter_list->count() == 0) return;
   __move_cursor(cursor_pos, -1, plotter_list->count());
}


void PlotterListWidget::move_cursor_down()
{
   if (!plotter_list || plotter_list->count() == 0) return;
   __move_cursor(cursor_pos, 1, plotter_list->count());
}


void PlotterListWidget::on_draw()
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

   for (auto &plotter : plotter_list->get_list_ref())
   {
      fullscore::ui::PlotterListItemRenderComponent plotter_list_item_render_component(plotter, text_font, al_color_name("gray"), width);

      placement.start_transform();
      plotter_list_item_render_component.render();

      placement.restore_transform();
      placement.position += vec2d(0, plotter_list_item_render_component.get_height());
   }
}


