



#include<fullscore/components/measure_grid_render_component.h>

#include <fullscore/models/measure_grid.h>




MeasureGridRenderComponent::MeasureGridRenderComponent(MeasureGrid *measure_grid, float full_measure_width, float staff_height)
   : measure_grid(measure_grid)
   , full_measure_width(full_measure_width)
   , staff_height(staff_height)
{}




MeasureGridRenderComponent::~MeasureGridRenderComponent()
{}




void MeasureGridRenderComponent::render()
{
   if (!measure_grid) return;

   // draw barlines
   TimeSignature previous_time_signature = TimeSignature(0, 0, 0);
   for (int x=0; x<measure_grid.get_num_measures(); x++)
   {
      Measure *measure = measure_grid.get_measure(x, 0);
      TimeSignature time_signature = measure_grid.get_time_signature(x);
      TimeSignatureRenderComponent time_signature_render_component(&time_signature);
      float x_pos = x * FULL_MEASURE_WIDTH;

      al_draw_line(x_pos, 0, x_pos, STAFF_HEIGHT * measure_grid.get_num_staves(), color::color(color::black, 0.2), 1.0);
      if (time_signature != previous_time_signature)
         time_signature_render_component.render(x_pos, -50);

      previous_time_signature = time_signature;
   }

   // draw the notes and measures
   Note *hovered_note = get_note_at_cursor();

   for (int y=0; y<measure_grid.get_num_staves(); y++)
      for (int x=0; x<measure_grid.get_num_measures(); x++)
      {
         Measure *measure = measure_grid.get_measure(x,y);
         music_engraver.draw(measure, x*FULL_MEASURE_WIDTH, y*STAFF_HEIGHT + STAFF_HEIGHT/2, FULL_MEASURE_WIDTH);

         // draw the notes
         float x_cursor = 0;
         for (unsigned i=0; i<measure->notes.size(); i++)
         {
            int xx = x * FULL_MEASURE_WIDTH;
            int yy = y * STAFF_HEIGHT;
            Note &note = measure->notes[i];
            float width = DurationHelper::get_length(note.duration, note.dots) * FULL_MEASURE_WIDTH;

            // draw some debug info on the note
            if (showing_debug_data)
            {
               ALLEGRO_FONT *text_font = Framework::font("DroidSans.ttf 20");
               al_draw_text(text_font, color::white, xx+x_cursor, yy, 0, tostring(note.scale_degree).c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+20, 0, (tostring(note.duration) + "(" + tostring(note.dots) + ")").c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+40, 0, tostring(note.playback_info.start_time).c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+60, 0, tostring(note.playback_info.end_time).c_str());
            }

            x_cursor += width;
         }
      }

   // draw a hilight box under the focused measure
   Measure *measure = get_measure_at_cursor();
   Note *note = get_note_at_cursor();

   if (get_measure_at_cursor())
   {
      float measure_width = get_measure_width(*measure) * FULL_MEASURE_WIDTH;
      // fill
      al_draw_filled_rounded_rectangle(measure_cursor_x*FULL_MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT,
         measure_cursor_x*FULL_MEASURE_WIDTH+measure_width, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
         4, 4, color::color(color::aliceblue, 0.2));

      // outline
      if (is_measure_target_mode())
         al_draw_rounded_rectangle(measure_cursor_x*FULL_MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT,
            measure_cursor_x*FULL_MEASURE_WIDTH+measure_width, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
            4, 4, color::color(color::aliceblue, 0.7), 2.0);
   }

   // draw a hilight box under the focused note
   if (measure && note)
   {
      float measure_cursor_real_x = get_measure_cursor_real_x();
      float measure_cursor_real_y = get_measure_cursor_real_y();
      float note_real_offset_x = get_measure_length_to_note(*measure, note_cursor_x) * FULL_MEASURE_WIDTH;
      float note_width = DurationHelper::get_length(note->duration, note->dots) * FULL_MEASURE_WIDTH;

      // fill
      al_draw_filled_rounded_rectangle(
            measure_cursor_real_x + note_real_offset_x,
            measure_cursor_real_y,
            measure_cursor_real_x + note_real_offset_x + note_width,
            measure_cursor_real_y + STAFF_HEIGHT,
            6,
            6,
            color::color(color::pink, 0.4)
         );

      // outline
      if (is_note_target_mode())
         al_draw_rounded_rectangle(
               measure_cursor_real_x + note_real_offset_x,
               measure_cursor_real_y,
               measure_cursor_real_x + note_real_offset_x + note_width,
               measure_cursor_real_y + STAFF_HEIGHT,
               6,
               6,
               color::mix(color::color(color::pink, 0.8), color::black, 0.3),
               2.0
            );
   }
}




