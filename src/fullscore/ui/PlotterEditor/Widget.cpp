

#include <fullscore/UI/PlotterEditor/Widget.hpp>

#include <fullscore/UI/PlotterEditor/Actions.hpp>
#include <fullscore/UI/PlotterEditor/RenderComponents/Widget.hpp>
#include <fullscore/models/plotters/base.h>
#include <allegro_flare/allegro_flare.h>


namespace UI::PlotterEditor
{


Widget::Widget(UIWidget *parent, Plotter::Base *plotter)
   : UIWidget(parent, "PlotterEditor", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
   , plotter(plotter)
{
}


Widget::~Widget()
{
}


std::vector<std::string> Widget::get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt)
{
   return keyboard_command_mapper.get_mapping(al_keycode, shift, ctrl, alt);
}


void Widget::on_draw()
{
   RenderComponents::Widget(this).render();
}


} // namespace UI::PlotterEditor


