

#include <fullscore/UI/ComponentTemplate/Widget.hpp>

#include <fullscore/UI/ComponentTemplate/RenderComponents/Widget.hpp>
#include <fullscore/UI/ComponentTemplate/Actions.hpp>
#include <allegro_flare/allegro_flare.h>


namespace UI::ComponentTemplate
{


Widget::Widget(UIWidget *parent, RenderComponents::Widget *render_component)
   : UIWidget(parent, "ComponentTemplate", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
   , render_component(render_component)
   , keyboard_command_mapper()
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
   if (render_component) render_component->render();
}


} // namespace UI::ComponentTemplate


