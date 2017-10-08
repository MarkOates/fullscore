



#include<fullscore/components/grid_render_component.h>

#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>
#include <allegro_flare/useful.h>
#include <fullscore/models/staves/base.h>
#include <fullscore/models/staves/harmonic_analysis.h>
#include <fullscore/models/staves/tempo.h>
#include <fullscore/components/harmonic_analysis_symbol_render_component.hpp>
#include <fullscore/components/measure_render_component.h>
#include <fullscore/components/tempo_marking_render_component.hpp>
#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/grid_helper.h>
#include <fullscore/models/Note.h>
#include <fullscore/models/grid.h>
#include <fullscore/models/reference_cursor.h>
#include <fullscore/services/music_engraver.h>




GridRenderComponent::GridRenderComponent(Grid *grid, MusicEngraver *music_engraver, ReferenceCursor *reference_cursor, float full_measure_width, float staff_height)
   : grid(grid)
   , music_engraver(music_engraver)
   , reference_cursor(reference_cursor)
   , full_measure_width(full_measure_width)
   , staff_height(staff_height)
   , showing_debug_data(false)
{}




GridRenderComponent::~GridRenderComponent()
{}




void GridRenderComponent::set_showing_debug_data(bool show)
{
   showing_debug_data = show;
}



void GridRenderComponent::render()
{
   if (!grid || !music_engraver) return;

   int reference_cursor_x = -1;
   int reference_cursor_y = -1;

   if (reference_cursor && reference_cursor->is_on_grid(grid))
   {
      reference_cursor_x = reference_cursor->get_x();
      reference_cursor_y = reference_cursor->get_y();
   }

   // draw barlines
   TimeSignature previous_time_signature = TimeSignature(0, Duration());
   for (int x=0; x<grid->get_num_measures(); x++)
   {
      float x_pos = GridHelper::get_length_to_measure(*grid, x) * full_measure_width;
      TimeSignature time_signature = grid->get_time_signature(x);
      TimeSignatureRenderComponent time_signature_render_component(&time_signature);

      // draw time signature
      if (time_signature != previous_time_signature) time_signature_render_component.render(x_pos, -50);

      previous_time_signature = time_signature;
   }

   float y_counter = 0;

   // draw the notes and measures
   for (int y=0; y<grid->get_num_staves(); y++)
   {
      Staff::Base *staff = grid->get_staff(y);
      if (!staff) continue;

      float this_staff_height = staff_height * staff->get_height();
      float this_staff_half_height = this_staff_height * 0.5;

      ALLEGRO_FONT *text_font = Framework::font("plantin-mt-light.ttf 22");
      ALLEGRO_FONT *analysis_font = Framework::font("plantin-mt-light.ttf 36");

      // draw the row name
      float row_middle_y = y_counter + this_staff_height * 0.5;
      float label_text_top_y = row_middle_y - al_get_font_line_height(text_font) * 0.5;
      al_draw_text(text_font, color::black, -30, label_text_top_y, ALLEGRO_ALIGN_RIGHT, grid->get_voice_name(y).c_str());

      // horizontal guide line for the staff
      if (staff->is_type("instrument"))
      {
         float width = GridHelper::get_width(*grid);
         al_draw_line(0, row_middle_y, width * full_measure_width, row_middle_y, color::color(color::black, 0.2), 1.0);
      }

      // draw the measures
      for (int x=0; x<grid->get_num_measures(); x++)
      {
         float x_pos = GridHelper::get_length_to_measure(*grid, x) * full_measure_width;
         float x_pos_plus_width = GridHelper::get_length_to_measure(*grid, x+1) * full_measure_width;
         float real_measure_width = x_pos_plus_width - x_pos;

         if (staff->is_type("instrument"))
         {
            // draw barline
            al_draw_line(x_pos_plus_width, row_middle_y-this_staff_half_height, x_pos_plus_width, row_middle_y+this_staff_half_height, color::color(color::black, 0.2), 1.0);
         }
         if (staff->is_type("tempo"))
         {
            Staff::Tempo &tempo_staff = static_cast<Staff::Tempo &>(*staff);
            std::vector<std::pair<TempoMarking, float>> tempo_markings_in_measure = tempo_staff.get_tempo_markings_in_measure(x);

            for (auto &marking : tempo_markings_in_measure)
            {
               TempoMarking &tempo_marking = std::get<0>(marking);
               float position = std::get<1>(marking);
               float marking_x_pos = x_pos + real_measure_width * position;

               TempoMarkingRenderComponent tempo_marking_render_component(text_font, marking_x_pos, label_text_top_y, tempo_marking);
               tempo_marking_render_component.render();
            }
         }
         if (staff->is_type("harmonic_analysis"))
         {
            Staff::HarmonicAnalysis &harmonic_analysis_staff = static_cast<Staff::HarmonicAnalysis &>(*staff);
            std::vector<std::pair<BeatCoordinate, HarmonicAnalysisSymbol>> harmonic_analysis_symbols_in_measure = harmonic_analysis_staff.get_symbols_in_measure(x);

            for (auto &marking : harmonic_analysis_symbols_in_measure)
            {
               BeatCoordinate beat_coordinate = std::get<0>(marking);
               HarmonicAnalysisSymbol &harmonic_analysis_symbol = std::get<1>(marking);
               float marking_x_pos = x_pos + (full_measure_width * 0.25 * beat_coordinate.get_x_offset());

               HarmonicAnalysisSymbolRenderComponent harmonic_analysis_symbol_render_component(analysis_font, text_font, marking_x_pos, label_text_top_y, harmonic_analysis_symbol);
               harmonic_analysis_symbol_render_component.render();
            }
         }
         if (staff->is_type("measure_numbers"))
         {
            al_draw_text(text_font, color::black, x_pos+5, label_text_top_y, ALLEGRO_ALIGN_LEFT, tostring(x).c_str());
            continue;
         }

         // draw the reference_cursor
         bool draw_reference_cursor = (y == reference_cursor_y && x == reference_cursor_x);
         if (draw_reference_cursor)
         {
            float reference_cursor_height = 20;
            float reference_cursor_width = 18;
            float reference_cursor_hwidth = reference_cursor_width * 0.5;

            al_draw_filled_triangle(
                  x_pos, y_counter,
                  x_pos-reference_cursor_hwidth, y_counter-reference_cursor_height,
                  x_pos+reference_cursor_hwidth, y_counter-reference_cursor_height,
                  color::darkorange);
         }

         // draw the measure
         Measure::Base *measure = grid->get_measure(x,y);
         if (!measure) continue;

         // this is the hacky measure for providing context-relative transformations when rendering
         // (but, we shouldn't be doing transformations inside the renderer, so there needs to be a different approach)
         static Measure::Basic *context_measure = new Measure::Basic({Note(0), Note(2), Note(4), Note(5), Note(7), Note(9), Note(11)});

         // render the actual measure
         MeasureRenderComponent measure_render_component(context_measure, measure, music_engraver, full_measure_width, x_pos, y_counter, row_middle_y, this_staff_height, showing_debug_data);
         measure_render_component.render();
      }

      y_counter += this_staff_height;
   }
}




