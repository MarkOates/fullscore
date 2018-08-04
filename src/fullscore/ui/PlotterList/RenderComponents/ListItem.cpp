

#include <fullscore/UI/PlotterList/RenderComponents/ListItem.hpp>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


namespace fullscore
{
namespace UI
{
namespace PlotterList
{
namespace RenderComponents
{


std::string ListItem::STATE_NORMAL = "normal";


std::string ListItem::STATE_FOCUSED = "focused";


std::string ListItem::STATE_SELECTED = "selected";


ListItem::ListItem(Plotter::Base* plotter, ALLEGRO_FONT* font, float width, float height)
   : plotter(plotter)
   , state(STATE_NORMAL)
   , font(font)
   , width(width)
   , height(height)
{
}


ListItem::~ListItem()
{
}


void ListItem::set_font(ALLEGRO_FONT* font)
{
   this->font = font;
}


void ListItem::set_width(float width)
{
   this->width = width;
}


void ListItem::set_height(float height)
{
   this->height = height;
}


Plotter::Base* ListItem::get_plotter()
{
   return plotter;
}


std::string ListItem::get_state()
{
   return state;
}


ALLEGRO_FONT* ListItem::get_font()
{
   return font;
}


float ListItem::get_width()
{
   return width;
}


float ListItem::get_height()
{
   return height;
}


void ListItem::render()
{
if (!font) throw std::runtime_error("missing font in PlotterListItemRenderComponent");

al_draw_text(font, al_color_name("black"), 20, 15, ALLEGRO_ALIGN_LEFT, plotter->get_type().c_str());
al_draw_filled_rectangle(0, 0, 10, height, al_color_name(state == STATE_SELECTED ? "gray" : "darkgray"));
al_draw_rectangle(0, 0, width, height, al_color_name(state == STATE_FOCUSED ? "white" : "gray"), 2.0);
}

void ListItem::set_state_normal()
{
state = STATE_NORMAL;
}

void ListItem::set_state_focused()
{
state = STATE_FOCUSED;
}

void ListItem::set_state_selected()
{
state = STATE_SELECTED;
}
} // namespace RenderComponents
} // namespace PlotterList
} // namespace UI
} // namespace fullscore


