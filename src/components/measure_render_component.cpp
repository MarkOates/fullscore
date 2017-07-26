


#include <fullscore/components/measure_render_component.h>

#include <allegro_flare/framework.h>
#include <allegro_flare/color.h>
#include <allegro_flare/useful_php.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/models/measure.h>
#include <fullscore/services/music_engraver.h>



float __get_measure_width(Measure::Base *m)  // TODO: should probably use a helper
{
   if (!m) return 0;
   float sum = 0;
   for (auto &note : m->get_notes_copy())  // TODO: ineffecient use of get_notes_copy()
      sum += DurationHelper::get_length(note.duration.denominator, note.duration.dots);
   return sum;
}



MeasureRenderComponent::MeasureRenderComponent(Measure::Base *measure, MusicEngraver *music_engraver, float full_measure_width, float x_pos, float y_pos, float row_middle_y, float staff_height, bool showing_debug_data)
   : measure(measure)
   , music_engraver(music_engraver)
   , full_measure_width(full_measure_width)
   , x_pos(x_pos)
   , y_pos(y_pos)
   , row_middle_y(row_middle_y)
   , staff_height(staff_height)
   , showing_debug_data(showing_debug_data)
{}



void MeasureRenderComponent::render()
{
   ALLEGRO_COLOR measure_block_color = color::color(color::white, 0.2);

   int measure_width = 16;

   if (measure->get_num_notes() > 0)
      measure_width = __get_measure_width(measure) * full_measure_width;

   if (measure->is_type("reference"))
      measure_block_color = color::color(color::yellow, 0.2);
   else if (measure->is_type("stack"))
      measure_block_color = color::color(color::red, 0.2);
   else if (measure->is_type("static"))
      measure_block_color = color::color(color::dodgerblue, 0.1);
   else if (measure->is_type("basic"))
      ALLEGRO_COLOR measure_block_color = color::color(color::black, 0.075);

   al_draw_filled_rounded_rectangle(x_pos, row_middle_y-staff_height/2,
         x_pos+measure_width, row_middle_y+staff_height/2,
         4, 4, measure_block_color);

   music_engraver->draw(measure, x_pos, y_pos + staff_height/2, full_measure_width);

   // draw debug info on the note
   if (showing_debug_data)
   {
      ALLEGRO_FONT *text_font = Framework::font("DroidSans.ttf 20");
      float x_cursor = x_pos;

      for (auto &note : measure->get_notes_copy())
      {
         float width = DurationHelper::get_length(note.duration.denominator, note.duration.dots) * full_measure_width;

         al_draw_text(text_font, color::white, x_cursor, y_pos, 0, tostring(note.pitch.scale_degree).c_str());
         al_draw_text(text_font, color::white, x_cursor, y_pos+20, 0, (tostring(note.duration.denominator) + "(" + tostring(note.duration.dots) + ")").c_str());

         x_cursor += width;
      }
   }
}



