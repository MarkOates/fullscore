



#include <fullscore/components/GridRenderComponent.h>

#include <allegro_flare/color.h>
#include <allegro_flare/framework.h>
#include <allegro_flare/useful.h>
#include <fullscore/models/staves/Base.h>
#include <fullscore/models/staves/HarmonicAnalysis.h>
#include <fullscore/models/staves/Tempo.h>
#include <fullscore/components/HarmonicAnalysisSymbolRenderComponent.h>
#include <fullscore/components/MeasureRenderComponent.h>
#include <fullscore/components/TempoMarkingRenderComponent.h>
#include <fullscore/components/TimeSignatureRenderComponent.h>
#include <fullscore/helpers/DurationHelper.h>
#include <fullscore/helpers/GridDimensionsHelper.h>
#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/models/Grid.h>
#include <fullscore/models/Staff.h>
#include <fullscore/services/MusicEngraver.h>




GridRenderComponent::GridRenderComponent(Grid *grid, MusicEngraver *music_engraver, float full_measure_width, float staff_height, int focused_floating_measure_id, bool is_measure_target, int note_cursor_x)
   : grid(grid)
   , music_engraver(music_engraver)
   , full_measure_width(full_measure_width)
   , staff_height(staff_height)
   , showing_debug_data(false)
   , focused_floating_measure_id(focused_floating_measure_id)
   , is_measure_target(is_measure_target)
   , note_cursor_x(note_cursor_x)
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

   // draw barlines
   TimeSignature previous_time_signature = TimeSignature(0, Duration());
   for (int x=0; x<grid->get_num_barlines(); x++)
   {
      float x_pos = GridDimensionsHelper::get_length_to_measure(*grid, x) * full_measure_width;
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
      if (staff->is_type(Staff::TYPE_IDENTIFIER_INSTRUMENT))
      {
         float width = GridDimensionsHelper::get_width(*grid);
         al_draw_line(0, row_middle_y, width * full_measure_width, row_middle_y, color::color(color::black, 0.2), 1.0);
      }

      // draw the measures
      for (int x=0; x<grid->get_num_barlines(); x++)
      {
         float x_pos = GridDimensionsHelper::get_length_to_measure(*grid, x) * full_measure_width;
         float x_pos_plus_width = GridDimensionsHelper::get_length_to_measure(*grid, x+1) * full_measure_width;
         float real_measure_width = x_pos_plus_width - x_pos;

         if (staff->is_type(Staff::TYPE_IDENTIFIER_INSTRUMENT))
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

         //
         // draw the "floating measures"
         //

         // this is the hacky measure for providing context-relative transformations when rendering
         // (but, we shouldn't be doing transformations inside the renderer, so there needs to be a different approach)
         static Measure::Basic *context_measure = new Measure::Basic({Note(0), Note(2), Note(4), Note(5), Note(7), Note(9), Note(11)});

         for (auto &floating_measure : FloatingMeasure::find_at_staff_and_barline(staff->get_id(), x))
         {
            float floating_measure_x_offset = floating_measure->get_grid_coordinate().get_grid_horizontal_coordinate().get_beat_coordinate().get_x_offset() * full_measure_width / 4.0;
            bool is_focused = (focused_floating_measure_id == floating_measure->get_id());
            Measure::Base *floating_measure_measure = Measure::find(floating_measure->get_measure_id(), Measure::FIND_OPTION_RAISE_NOT_FOUND);
            MeasureRenderComponent measure_render_component(context_measure, floating_measure_measure, music_engraver, full_measure_width, x_pos + floating_measure_x_offset, y_counter, row_middle_y, this_staff_height, showing_debug_data, is_focused, is_measure_target, note_cursor_x);
            measure_render_component.render();
         }
      }

      y_counter += this_staff_height;
   }
}


