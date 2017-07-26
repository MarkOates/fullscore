



#include<fullscore/components/measure_grid_render_component.h>

#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>
#include <allegro_flare/useful.h>
#include <fullscore/components/measure_render_component.h>
#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/measure_grid_helper.h>
#include <fullscore/models/note.h>
#include <fullscore/models/measure_grid.h>
#include <fullscore/models/reference_cursor.h>
#include <fullscore/services/music_engraver.h>




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

         Measure::Base *measure = measure_grid->get_measure(x,y);
         if (!measure) continue;

         MeasureRenderComponent measure_render_component(measure, music_engraver, full_measure_width, x_pos, y_pos, row_middle_y, staff_height, showing_debug_data);
         measure_render_component.render();
      }
   }
}




