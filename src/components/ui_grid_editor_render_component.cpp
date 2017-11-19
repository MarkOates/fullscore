


#include <fullscore/components/ui_grid_editor_render_component.h>

#include <allegro_flare/gui/surface_areas/box_padded.h>
#include <allegro_flare/gui/surface_areas/box_padded.h>
#include <fullscore/components/grid_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/grid_dimensions_helper.h>
#include <fullscore/models/playback_control.h>
#include <fullscore/services/music_engraver.h>
#include <allegro_flare/allegro_flare.h>
#include <cmath>



UIGridEditorRenderComponent::UIGridEditorRenderComponent(UIGridEditor &ui_grid_editor)
   : ui_grid_editor(ui_grid_editor)
{
}



UIGridEditorRenderComponent::~UIGridEditorRenderComponent()
{
}



void UIGridEditorRenderComponent::render()
{
   Grid &grid                                                  = ui_grid_editor.grid;
   MusicEngraver &music_engraver                               = ui_grid_editor.music_engraver;
   float &FULL_MEASURE_WIDTH                                   = ui_grid_editor.FULL_MEASURE_WIDTH;
   float &STAFF_HEIGHT                                         = ui_grid_editor.STAFF_HEIGHT;
   UIGridEditor::state_t &state                                = ui_grid_editor.state;
   UISurfaceAreaBase *&surface_area                            = ui_grid_editor.surface_area;
   bool &showing_debug_data                                    = ui_grid_editor.showing_debug_data;
   int &grid_cursor_y                                       = ui_grid_editor.grid_cursor_y;
   int &note_cursor_x                                          = ui_grid_editor.note_cursor_x;
   PlaybackControl &playback_control                           = ui_grid_editor.playback_control;


   // get_width_of_score
   float grid_real_width = GridDimensionsHelper::get_length_to_measure(grid, grid.get_num_barlines()) * FULL_MEASURE_WIDTH;
   float grid_real_height = grid.get_height() * STAFF_HEIGHT;

   // draw the bounding box for the widget
   float pt, pr, pb, pl;
   UISurfaceAreaBoxPadded *sa = static_cast<UISurfaceAreaBoxPadded *>(surface_area);
   sa->get_padding(&pt, &pr, &pb, &pl);

   if (state == UIGridEditor::STATE_ACTIVE)
   {
      // draw a background for the score
      float padding = 30;
      al_draw_filled_rectangle(-padding, -padding,
         grid_real_width + padding, grid_real_height + padding,
         color::color(color::blanchedalmond, 0.2));
   }

   // render the measure grid
   GridRenderComponent grid_render_component(&grid, &music_engraver, FULL_MEASURE_WIDTH, STAFF_HEIGHT);
   grid_render_component.set_showing_debug_data(showing_debug_data);
   grid_render_component.render();

   if (state != UIGridEditor::STATE_ACTIVE) return;

   // draw a hilight box under the focused measure
   Measure::Base *measure = ui_grid_editor.get_measure_at_cursor();

   Note *note = ui_grid_editor.get_note_at_cursor();
   float CACHED_get_grid_cursor_real_x = ui_grid_editor.get_grid_cursor_real_x();
   float CACHED_get_grid_cursor_real_y = ui_grid_editor.get_grid_cursor_real_y();

   // draw the measure

   float measure_width = ui_grid_editor.get_measure_width(measure) * FULL_MEASURE_WIDTH;
   if (measure && measure->get_num_notes() == 0) measure_width = 16;

   // measure box fill
   al_draw_filled_rounded_rectangle(CACHED_get_grid_cursor_real_x, GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y)*STAFF_HEIGHT,
      CACHED_get_grid_cursor_real_x+measure_width, GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y)*STAFF_HEIGHT+GridDimensionsHelper::get_height_of_staff(grid, grid_cursor_y)*STAFF_HEIGHT,
      4, 4, color::color(color::aliceblue, 0.2));

   // measure box outline
   if (ui_grid_editor.is_measure_target_mode())
   {
      float thickness = 2.0;
      float h_thickness = thickness * 0.5;

      al_draw_rounded_rectangle(
            CACHED_get_grid_cursor_real_x - h_thickness*2,
            GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y)*STAFF_HEIGHT - h_thickness*2,
            CACHED_get_grid_cursor_real_x+measure_width + h_thickness*2,
            GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y)*STAFF_HEIGHT+GridDimensionsHelper::get_height_of_staff(grid, grid_cursor_y)*STAFF_HEIGHT + h_thickness*2,
            4,
            4,
            color::color(color::black, 0.3),
            thickness
         );

      al_draw_rounded_rectangle(
            CACHED_get_grid_cursor_real_x - h_thickness,
            GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y)*STAFF_HEIGHT - h_thickness,
            CACHED_get_grid_cursor_real_x+measure_width + h_thickness,
            GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y)*STAFF_HEIGHT+GridDimensionsHelper::get_height_of_staff(grid, grid_cursor_y)*STAFF_HEIGHT + h_thickness,
            4,
            4,
            color::color(color::aliceblue, 0.7),
            thickness
         );
   }

   // left bar (blinking)

   ALLEGRO_COLOR cursor_color = color::color(color::white, sin(Framework::time_now*5) + 0.5);
   al_draw_line(CACHED_get_grid_cursor_real_x, CACHED_get_grid_cursor_real_y,
         CACHED_get_grid_cursor_real_x, CACHED_get_grid_cursor_real_y+GridDimensionsHelper::get_height_of_staff(grid, grid_cursor_y)*STAFF_HEIGHT,
         cursor_color, 3.0);

   // draw a hilight box at the focused note
   if (ui_grid_editor.is_note_target_mode() && note)
   {
      float note_real_offset_x = ui_grid_editor.get_measure_length_to_note(measure, note_cursor_x) * FULL_MEASURE_WIDTH;
      float real_note_width = DurationHelper::get_length(note->duration.denominator, note->duration.dots) * FULL_MEASURE_WIDTH;

      // note box fill
      al_draw_filled_rounded_rectangle(
            CACHED_get_grid_cursor_real_x + note_real_offset_x,
            CACHED_get_grid_cursor_real_y,
            CACHED_get_grid_cursor_real_x + note_real_offset_x + real_note_width,
            CACHED_get_grid_cursor_real_y + GridDimensionsHelper::get_height_of_staff(grid, grid_cursor_y)*STAFF_HEIGHT,
            6,
            6,
            color::color(color::pink, 0.4)
         );
   }

   // draw the playhead
   float playhead_x = playback_control.position * FULL_MEASURE_WIDTH;
   float playhead_y = -40;
   al_draw_line(playhead_x, playhead_y, playhead_x, grid_real_height + 40, color::color(color::lightcyan, 0.5), 3);
   al_draw_filled_triangle(playhead_x-8, playhead_y-8, playhead_x+8, playhead_y-8, playhead_x, playhead_y+6, color::lightcyan);
   al_draw_filled_rectangle(playhead_x-8, playhead_y-8-14, playhead_x+8, playhead_y-8, color::lightcyan);
}




