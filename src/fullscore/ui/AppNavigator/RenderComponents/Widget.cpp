

#include <fullscore/UI/AppNavigator/RenderComponents/Widget.hpp>

#include <fullscore/UI/AppNavigator/Widget.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace UI::AppNavigator::RenderComponents
{


Widget::Widget(UI::AppNavigator::Widget *widget)
   : widget(widget)
{}


void Widget::render()
{
   if (!widget) throw std::runtime_error("Cannot render AppNavigator::RenderComponent::Widget with nullptr widget");

   float &width = widget->place.size.x;
   float &height = widget->place.size.y;

   al_draw_filled_rectangle(0, 0, width, height, al_color_name("gray"));

   return;
}


} // namespace UI::AppNavigator::RenderComponents


