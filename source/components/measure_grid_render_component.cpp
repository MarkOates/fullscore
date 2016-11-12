



#include<fullscore/components/measure_grid_render_component.h>

#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>
#include <allegro_flare/useful.h>
#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/measure_grid_helper.h>
#include <fullscore/models/note.h>
#include <fullscore/models/measure_grid.h>
#include <fullscore/constants.h>
#include <fullscore/music_engraver.h>




MeasureGridRenderComponent::MeasureGridRenderComponent(MeasureGrid *measure_grid, MusicEngraver *music_engraver, float full_measure_width, float staff_height)
   : measure_grid(measure_grid)
   , music_engraver(music_engraver)
   , full_measure_width(full_measure_width)
   , staff_height(staff_height)
   , showing_debug_data(false)
{}




MeasureGridRenderComponent::~MeasureGridRenderComponent()
{}




void MeasureGridRenderComponent::render()
{
   if (!measure_grid || !music_engraver) return;

   // draw barlines
   TimeSignature previous_time_signature = TimeSignature(0, 0, 0);
   for (int x=0; x<measure_grid->get_num_measures(); x++)
   {
      Measure *measure = measure_grid->get_measure(x, 0);
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
      for (int x=0; x<measure_grid->get_num_measures(); x++)
      {
         Measure *measure = measure_grid->get_measure(x,y);
         float x_pos = MeasureGridHelper::get_length_to_measure(*measure_grid, x) * full_measure_width;
         music_engraver->draw(measure, x_pos, y*staff_height + staff_height/2, full_measure_width);

         // draw debug info on the note
         if (showing_debug_data)
         {
            float x_cursor = 0;
            for (unsigned i=0; i<measure->notes.size(); i++)
            {
               int xx = x * full_measure_width;
               int yy = y * staff_height;
               Note &note = measure->notes[i];
               float width = DurationHelper::get_length(note.duration, note.dots) * full_measure_width;

               ALLEGRO_FONT *text_font = Framework::font("DroidSans.ttf 20");
               al_draw_text(text_font, color::white, xx+x_cursor, yy, 0, tostring(note.scale_degree).c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+20, 0, (tostring(note.duration) + "(" + tostring(note.dots) + ")").c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+40, 0, tostring(note.playback_info.start_time).c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+60, 0, tostring(note.playback_info.end_time).c_str());

               x_cursor += width;
            }
         }
      }
}




