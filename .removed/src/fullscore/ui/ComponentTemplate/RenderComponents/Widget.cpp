

#include <fullscore/UI/ComponentTemplate/RenderComponents/Widget.hpp>

#include <fullscore/UI/ComponentTemplate/Widget.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace UI::ComponentTemplate::RenderComponents
{


Widget::Widget(UI::ComponentTemplate::Widget *widget)
   : widget(widget)
{}


void Widget::render()
{
   if (!widget) throw std::runtime_error("Cannot render ComponentTemplate::RenderComponent::Widget with nullptr widget");

   float &width = widget->place.size.x;
   float &height = widget->place.size.y;

   al_draw_filled_rectangle(0, 0, width, height, al_color_name("gray"));

   return;
}


} // namespace UI::ComponentTemplate::RenderComponents


