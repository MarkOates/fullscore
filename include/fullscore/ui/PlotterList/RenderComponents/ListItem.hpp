#pragma once


#include <allegro5/allegro_font.h>
#include <fullscore/models/plotters/Base.h>
#include <string>


namespace fullscore
{
   namespace UI
   {
      namespace PlotterList
      {
         namespace RenderComponents
         {
            class ListItem
            {
            private:
               static std::string STATE_NORMAL;
               static std::string STATE_FOCUSED;
               static std::string STATE_SELECTED;
               Plotter::Base* plotter;
               std::string state;
               ALLEGRO_FONT* font;
               float width;
               float height;

            public:
               ListItem(Plotter::Base* plotter=nullptr, ALLEGRO_FONT* font=nullptr, float width=300, float height=60);
               ~ListItem();

               void set_font(ALLEGRO_FONT* font);
               void set_width(float width);
               void set_height(float height);

               Plotter::Base* get_plotter();
               std::string get_state();
               ALLEGRO_FONT* get_font();
               float get_width();
               float get_height();
            void render();
            void set_state_normal();
            void set_state_focused();
            void set_state_selected();
            };
         }
      }
   }
}



