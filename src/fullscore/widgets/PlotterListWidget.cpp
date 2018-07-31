

#include <fullscore/widgets/PlotterListWidget.hpp>

#include <allegro_flare/gui/surface_areas/box.h>
#include <fullscore/ui/PlotterListRenderComponent.hpp>


PlotterListWidget::PlotterListWidget(UIWidget *parent, std::vector<Plotter::Base *> &plotters)
   : UIWidget(parent, "PlotterListWidget", new UISurfaceAreaBox(0, 0, 300, 200))
   , cursor_pos(0)
   , plotters(plotters)
{
}


PlotterListWidget::~PlotterListWidget()
{
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
   __move_cursor(cursor_pos, -1, plotters.size());
}


void PlotterListWidget::move_cursor_down()
{
   __move_cursor(cursor_pos, 1, plotters.size());
}


void PlotterListWidget::on_draw()
{
   for (auto &plotter : plotters)
   {
      fullscore::ui::PlotterListRenderComponent plotter_list_item_render_component(plotter);
      plotter_list_item_render_component.render();
   }
}


