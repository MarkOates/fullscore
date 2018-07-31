

#include <fullscore/ui/PlotterListRenderComponent.hpp>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace fullscore
{
namespace ui
{


PlotterListRenderComponent::PlotterListRenderComponent(Plotter::Base* plotter, ALLEGRO_COLOR color, float width, float height)
   : plotter(plotter)
   , state("normal")
   , color(color)
   , width(width)
   , height(height)
{
}


PlotterListRenderComponent::~PlotterListRenderComponent()
{
}


void PlotterListRenderComponent::set_color(ALLEGRO_COLOR color)
{
   this->color = color;
}


void PlotterListRenderComponent::set_width(float width)
{
   this->width = width;
}


void PlotterListRenderComponent::set_height(float height)
{
   this->height = height;
}


Plotter::Base* PlotterListRenderComponent::get_plotter()
{
   return plotter;
}


std::string PlotterListRenderComponent::get_state()
{
   return state;
}


ALLEGRO_COLOR PlotterListRenderComponent::get_color()
{
   return color;
}


float PlotterListRenderComponent::get_width()
{
   return width;
}


float PlotterListRenderComponent::get_height()
{
   return height;
}


void PlotterListRenderComponent::render()
{
al_draw_filled_rectangle(0, 0, 10, height, color);
al_draw_rectangle(0, 0, width, height, al_color_name("white"), 2.0);
}

void PlotterListRenderComponent::set_state_normal()
{
state = "normal";
}

void PlotterListRenderComponent::set_state_hilighted()
{
state = "hilighted";
}
} // namespace ui
} // namespace fullscore


