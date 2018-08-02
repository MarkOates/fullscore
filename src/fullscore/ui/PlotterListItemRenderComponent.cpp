

#include <fullscore/ui/PlotterListItemRenderComponent.hpp>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace fullscore
{
namespace ui
{


PlotterListItemRenderComponent::PlotterListItemRenderComponent(Plotter::Base* plotter, ALLEGRO_FONT* font, ALLEGRO_COLOR color, float width, float height)
   : plotter(plotter)
   , state("normal")
   , font(font)
   , color(color)
   , width(width)
   , height(height)
{
}


PlotterListItemRenderComponent::~PlotterListItemRenderComponent()
{
}


void PlotterListItemRenderComponent::set_font(ALLEGRO_FONT* font)
{
   this->font = font;
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


ALLEGRO_FONT* PlotterListItemRenderComponent::get_font()
{
   return font;
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
if (!font) throw std::runtime_error("missing font in PlotterListItemRenderComponent");
al_draw_text(font, al_color_name("black"), 20, 15, ALLEGRO_ALIGN_LEFT, "Basic");
al_draw_filled_rectangle(0, 0, 10, height, color);
al_draw_rectangle(0, 0, width, height, al_color_name(state == "hilighted" ? "white" : "gray"), 2.0);
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


