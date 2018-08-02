#pragma once


#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <fullscore/models/plotters/Base.h>
#include <string>


namespace fullscore
{
   namespace ui
   {
      class PlotterListItemRenderComponent
      {
      private:
         Plotter::Base* plotter;
         std::string state;
         ALLEGRO_FONT* font;
         ALLEGRO_COLOR color;
         float width;
         float height;

      public:
         PlotterListItemRenderComponent(Plotter::Base* plotter=nullptr, ALLEGRO_FONT* font=nullptr, ALLEGRO_COLOR color=al_color_name("gray"), float width=300, float height=60);
         ~PlotterListItemRenderComponent();

         void set_font(ALLEGRO_FONT* font);
         void set_color(ALLEGRO_COLOR color);
         void set_width(float width);
         void set_height(float height);

         Plotter::Base* get_plotter();
         std::string get_state();
         ALLEGRO_FONT* get_font();
         ALLEGRO_COLOR get_color();
         float get_width();
         float get_height();
      void render();
      void set_state_normal();
      void set_state_hilighted();
      };
   }
}



