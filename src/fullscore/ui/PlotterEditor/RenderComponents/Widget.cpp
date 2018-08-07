


#include <fullscore/UI/PlotterEditor/RenderComponents/Widget.hpp>

#include <fullscore/UI/PlotterEditor/Widget.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>


namespace UI::PlotterEditor::RenderComponents
{


Widget::Widget(UI::PlotterEditor::Widget *widget)
   : widget(widget)
{}


Widget::~Widget()
{
}


void Widget::render()
{
   if (!widget) throw std::runtime_error("Cannot render PlotterEditor::RenderComponent::Widget with nullptr widget");

   float &width = widget->place.size.x;
   float &height = widget->place.size.y;

   al_draw_filled_rectangle(0, 0, width, height, al_color_name("gray"));

   return;
}


} // namespace UI::PlotterEditor::RenderComponents


