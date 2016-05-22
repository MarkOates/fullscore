

#include <allegro5/allegro_primitives.h>
#include <allegro_flare/gui/surface_areas/box.h>
#include <fullscore/cell_instance.h>


UICellInstance::UICellInstance(UIWidget *parent, Cell *cell, float x, float y)
   : UIWidget(parent, new UISurfaceAreaBox(x, y, 100, 60))
{
}



void UICellInstance::on_draw()
{
   al_draw_filled_rounded_rectangle(0, 0, place.size.x, place.size.y, 4, 4, mouse_over ? color::dodgerblue : color::gray);
}



void UICellInstance::on_click()
{
}



void UICellInstance::on_mouse_enter()
{
}



void UICellInstance::on_mouse_leave()
{
}



void UICellInstance::on_mouse_move(float x, float y, float dx, float dy)
{
}



