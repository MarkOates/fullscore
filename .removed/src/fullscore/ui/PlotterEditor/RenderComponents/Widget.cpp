


#include <fullscore/UI/PlotterEditor/RenderComponents/Widget.hpp>

#include <fullscore/models/plotters/Base.h>
#include <fullscore/UI/PlotterEditor/Widget.hpp>
#include <fullscore/models/Plotter.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro_flare/framework.h>

#include <fullscore/services/MusicEngraver.h>
#include <fullscore/models/plotters/Destination.h>
#include <fullscore/models/plotters/Selector.hpp>
#include <fullscore/models/measures/Basic.h>
#include <fullscore/models/Note.h>


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
   std::string plotter_type = plotter->get_type();
   float &width = widget->place.size.x;
   float &height = widget->place.size.y;

   al_draw_filled_rectangle(0, 0, width, height, al_color_name("gray"));

   al_draw_text(text_font, color::white, 20, 20, ALLEGRO_ALIGN_LEFT, plotter_type.c_str());

   if (plotter_type == Plotter::TYPE_IDENTIFIER_BASE)
   {
      al_draw_text(text_font, color::aliceblue, 20, 60, ALLEGRO_ALIGN_LEFT, "[no interface for editing this type]");
   }
   else if (plotter_type == Plotter::TYPE_IDENTIFIER_BASIC)
   {
      al_draw_text(text_font, color::aliceblue, 20, 60, ALLEGRO_ALIGN_LEFT, "[no interface for editing this type]");
   }
   else if (plotter_type == Plotter::TYPE_IDENTIFIER_DESTINATION)
   {
      Plotter::Destination *destination_plotter = static_cast<Plotter::Destination *>(plotter);
      std::vector<Note> notes = destination_plotter->get_notes();
      Measure::Basic measure(destination_plotter->get_notes());
      MusicEngraver music_engraver;
      float divider_x = 130;
      float line_y = 50;
      float spacing_y = 20;
      float full_measure_width = 200;
      float staff_height = 20;

      ALLEGRO_FONT *label_font = Framework::font("plantin-mt-light.ttf 15");
      ALLEGRO_FONT *value_font = Framework::font("plantin-mt-light.ttf 15");

      al_draw_text(label_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_RIGHT, "Destinations: ");
      al_draw_textf(value_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_LEFT, "%i", destination_plotter->num_destinations());

      line_y += spacing_y;
      al_draw_text(label_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_RIGHT, "Notes: ");

      music_engraver.draw(&measure, divider_x, line_y + staff_height, full_measure_width, color::white, color::white);
   }
   else if (plotter_type == Plotter::TYPE_IDENTIFIER_SELECTOR)
   {
      Plotter::Selector *selector_plotter = static_cast<Plotter::Selector *>(plotter);
      std::vector<Note> notes = selector_plotter->get_notes();
      //InstrumentSelector::Interface *instrument_selector = selector_plotter->get_instrument_selector();
      float divider_x = 50;
      float line_y = 50;
      float spacing_y = 20;

      ALLEGRO_FONT *label_font = Framework::font("plantin-mt-light.ttf 15");
      ALLEGRO_FONT *value_font = Framework::font("plantin-mt-light.ttf 15");

      al_draw_text(label_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_RIGHT, "Selector: ");
      al_draw_text(value_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_LEFT, plotter_type.c_str());

      line_y += spacing_y;
      al_draw_text(label_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_RIGHT, "Notes: ");
      al_draw_text(value_font, color::white, divider_x, line_y, ALLEGRO_ALIGN_LEFT, "[not-implemented]");
   }

   return;
}


} // namespace UI::PlotterEditor::RenderComponents


