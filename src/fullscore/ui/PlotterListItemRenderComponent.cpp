

#include <fullscore/ui/PlotterListItemRenderComponent.hpp>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace fullscore
{
namespace ui
{


PlotterListItemRenderComponent::PlotterListItemRenderComponent(Plotter::Base* plotter, ALLEGRO_COLOR color, float width, float height)
   : plotter(plotter)
   , state("normal")
   , color(color)
   , width(width)
   , height(height)
{
}


PlotterListItemRenderComponent::~PlotterListItemRenderComponent()
{
}


void PlotterListItemRenderComponent::set_color(ALLEGRO_COLOR color)
{
   this->color = color;
}


void PlotterListItemRenderComponent::set_width(float width)
{
   this->width = width;
}


void PlotterListItemRenderComponent::set_height(float height)
{
   this->height = height;
}


Plotter::Base* PlotterListItemRenderComponent::get_plotter()
{
   return plotter;
}


std::string PlotterListItemRenderComponent::get_state()
{
   return state;
}


ALLEGRO_COLOR PlotterListItemRenderComponent::get_color()
{
   return color;
}


float PlotterListItemRenderComponent::get_width()
{
   return width;
}


float PlotterListItemRenderComponent::get_height()
{
   return height;
}


void PlotterListItemRenderComponent::render()
{
al_draw_filled_rectangle(0, 0, 10, height, color);
al_draw_rectangle(0, 0, width, height, al_color_name("white"), 2.0);
}

void PlotterListItemRenderComponent::set_state_normal()
{
state = "normal";
}

void PlotterListItemRenderComponent::set_state_hilighted()
{
state = "hilighted";
}
} // namespace ui
} // namespace fullscore


