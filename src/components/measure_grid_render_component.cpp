



#include<fullscore/components/measure_grid_render_component.h>

#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>
#include <allegro_flare/useful.h>
#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/measure_grid_helper.h>
#include <fullscore/models/note.h>
#include <fullscore/models/measure_grid.h>
#include <fullscore/services/music_engraver.h>
#include <fullscore/reference_cursor.h>




MeasureGridRenderComponent::MeasureGridRenderComponent(MeasureGrid *measure_grid, MusicEngraver *music_engraver, ReferenceCursor *reference_cursor, float full_measure_width, float staff_height)
   : measure_grid(measure_grid)
   , music_engraver(music_engraver)
   , reference_cursor(reference_cursor)
   , full_measure_width(full_measure_width)
   , staff_height(staff_height)
   , showing_debug_data(false)
{}




MeasureGridRenderComponent::~MeasureGridRenderComponent()
{}




void MeasureGridRenderComponent::set_showing_debug_data(bool show)
{
   showing_debug_data = show;
}



float __get_measure_width(Measure::Base *m)  // TODO: should probably use a helper
{
   if (!m) return 0;
   float sum = 0;
   for (auto &note : m->get_notes_copy())  // TODO: ineffecient use of get_notes_copy()
      sum += DurationHelper::get_length(note.duration.denominator, note.duration.dots);
   return sum;
}



void MeasureGridRenderComponent::render()
{
   if (!measure_grid || !music_engraver) return;

   int reference_cursor_x = -1;
   int reference_cursor_y = -1;

   if (reference_cursor && reference_cursor->is_on_measure_grid(measure_grid))
   {
      reference_cursor_x = reference_cursor->get_x();
      reference_cursor_y = reference_cursor->get_y();
   }

   // draw barlines
   TimeSignature previous_time_signature = TimeSignature(0, Duration());
   for (int x=0; x<measure_grid->get_num_measures(); x++)
   {
      float x_pos = MeasureGridHelper::get_length_to_measure(*measure_grid, x) * full_measure_width;
      TimeSignature time_signature = measure_grid->get_time_signature(x);
      TimeSignatureRenderComponent time_signature_render_component(&time_signature);

      // draw barline
      al_draw_line(x_pos, 0, x_pos, staff_height * measure_grid->get_num_staves(), color::color(color::black, 0.2), 1.0);

      // draw time signature
      if (time_signature != previous_time_signature) time_signature_render_component.render(x_pos, -50);

      previous_time_signature = time_signature;
   }

   // draw the notes and measures
   for (int y=0; y<measure_grid->get_num_staves(); y++)
   {
      ALLEGRO_FONT *text_font = Framework::font("DroidSans.ttf 20");
      int y_pos = y * staff_height;

      // draw the row name
      float row_middle_y = y_pos + staff_height * 0.5;
      float label_text_top_y = row_middle_y - al_get_font_line_height(text_font) * 0.5;
      al_draw_text(text_font, color::black, -30, label_text_top_y, ALLEGRO_ALIGN_RIGHT, measure_grid->get_voice_name(y).c_str());

      // draw the measures
      for (int x=0; x<measure_grid->get_num_measures(); x++)
      {
         // draw the reference_cursor
         float x_pos = MeasureGridHelper::get_length_to_measure(*measure_grid, x) * full_measure_width;

         bool draw_reference_cursor = (y == reference_cursor_y && x == reference_cursor_x);
         if (draw_reference_cursor)
         {
            float reference_cursor_height = 20;
            float reference_cursor_width = 18;
            float reference_cursor_hwidth = reference_cursor_width * 0.5;

            al_draw_filled_triangle(
                  x_pos, y_pos,
                  x_pos-reference_cursor_hwidth, y_pos-reference_cursor_height,
                  x_pos+reference_cursor_hwidth, y_pos-reference_cursor_height,
                  color::darkorange);
         }

         //draw the measure
         Measure::Base *measure = measure_grid->get_measure(x,y);
         if (!measure) continue;

         ALLEGRO_COLOR measure_block_color = color::color(color::white, 0.2);

         int measure_width = 16;

         if (measure)
         {
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
         }

         al_draw_filled_rounded_rectangle(x_pos, row_middle_y-staff_height/2,
            x_pos+measure_width, row_middle_y+staff_height/2,
            4, 4, measure_block_color);

         music_engraver->draw(measure, x_pos, y_pos + staff_height/2, full_measure_width);

         // draw debug info on the note
         if (showing_debug_data)
         {
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
   }
}




