


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
   Grid &grid                        = ui_grid_editor.grid;
   MusicEngraver &music_engraver     = ui_grid_editor.music_engraver;
   float &FULL_MEASURE_WIDTH         = ui_grid_editor.FULL_MEASURE_WIDTH;
   float &STAFF_HEIGHT               = ui_grid_editor.STAFF_HEIGHT;
   UIGridEditor::state_t &state      = ui_grid_editor.state;
   UISurfaceAreaBase *&surface_area  = ui_grid_editor.surface_area;
   bool &showing_debug_data          = ui_grid_editor.showing_debug_data;
   int &grid_cursor_y                = ui_grid_editor.grid_cursor_y;
   int &note_cursor_x                = ui_grid_editor.note_cursor_x;
   PlaybackControl &playback_control = ui_grid_editor.playback_control;
   int focused_floating_measure_id   = ui_grid_editor.floating_measure_cursor.get_floating_measure_id();


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
   GridRenderComponent grid_render_component(&grid, &music_engraver, FULL_MEASURE_WIDTH, STAFF_HEIGHT, focused_floating_measure_id);
   grid_render_component.set_showing_debug_data(showing_debug_data);
   grid_render_component.render();

   if (state != UIGridEditor::STATE_ACTIVE) return;


   // left bar (blinking)
   ALLEGRO_COLOR cursor_color = color::color(color::white, sin(Framework::time_now*5) + 0.5);
   al_draw_line(CACHED_get_grid_cursor_real_x, CACHED_get_grid_cursor_real_y,
         CACHED_get_grid_cursor_real_x, CACHED_get_grid_cursor_real_y+GridDimensionsHelper::get_height_of_staff(grid, grid_cursor_y)*STAFF_HEIGHT,
         cursor_color, 3.0);

   // draw the playhead
   float playhead_x = playback_control.position * FULL_MEASURE_WIDTH;
   float playhead_y = -40;
   al_draw_line(playhead_x, playhead_y, playhead_x, grid_real_height + 40, color::color(color::lightcyan, 0.5), 3);
   al_draw_filled_triangle(playhead_x-8, playhead_y-8, playhead_x+8, playhead_y-8, playhead_x, playhead_y+6, color::lightcyan);
   al_draw_filled_rectangle(playhead_x-8, playhead_y-8-14, playhead_x+8, playhead_y-8, color::lightcyan);
}




