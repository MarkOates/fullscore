


#include <fullscore/UI/PlotterEditor/RenderComponents/Widget.hpp>

#include <fullscore/models/plotters/Base.h>
#include <fullscore/UI/PlotterEditor/Widget.hpp>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/framework.h>


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

   ALLEGRO_FONT *text_font = Framework::font("plantin-mt-light.ttf 20");
   Plotter::Base *plotter = widget->get_plotter();
   float &width = widget->place.size.x;
   float &height = widget->place.size.y;

   al_draw_filled_rectangle(0, 0, width, height, al_color_name("gray"));

   al_draw_text(text_font, color::white, 20, 20, ALLEGRO_ALIGN_LEFT, plotter->get_type().c_str());

   return;
}


} // namespace UI::PlotterEditor::RenderComponents


