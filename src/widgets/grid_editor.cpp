



#include <fullscore/widgets/grid_editor.h>

#include <allegro_flare/allegro_flare.h>

#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/components/grid_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/grid_helper.h>
#include <cmath>




UIGridEditor::RenderingDependencies::RenderingDependencies(ReferenceCursor *reference_cursor)
   : reference_cursor(reference_cursor)
{}




void UIGridEditor::RenderingDependencies::set_reference_cursor(ReferenceCursor *reference_cursor)
{
   this->reference_cursor = reference_cursor;
}




UIGridEditor::UIGridEditor(UIWidget *parent, ReferenceCursor *reference_cursor)
   // the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
   : UIWidget(parent, "UIGridEditor", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
   , grid(0, 0)
   , playback_control()
   , rendering_dependencies(reference_cursor)
   , measure_cursor_x(0)
   , measure_cursor_y(0)
   , note_cursor_x(0)
   , edit_mode_target(MEASURE_TARGET)
   , mode(NORMAL_MODE)
   , state(STATE_INACTIVE) //TODO insure STATE_INACTIVE is a good initizliation value
   , music_engraver()
   , showing_debug_data(false)
   , STAFF_HEIGHT(80)
   , FULL_MEASURE_WIDTH(music_engraver.music_notation.get_quarter_note_spacing()*4)
{}




void UIGridEditor::on_draw()
{
   // get_width_of_score
   float grid_real_width = GridHelper::get_length_to_measure(grid, grid.get_num_measures()) * FULL_MEASURE_WIDTH;
   float grid_real_height = grid.get_height() * STAFF_HEIGHT;

   // draw the bounding box for the widget
   float pt, pr, pb, pl;
   UISurfaceAreaBoxPadded *sa = static_cast<UISurfaceAreaBoxPadded *>(surface_area);
   sa->get_padding(&pt, &pr, &pb, &pl);

   if (state == STATE_ACTIVE)
   {
      // draw a background for the score
      float padding = 30;
      al_draw_filled_rectangle(-padding, -padding,
         grid_real_width + padding, grid_real_height + padding,
         color::color(color::blanchedalmond, 0.2));
   }

   // render the measure grid
   GridRenderComponent grid_render_component(&grid, &music_engraver, rendering_dependencies.reference_cursor, FULL_MEASURE_WIDTH, STAFF_HEIGHT);
   grid_render_component.set_showing_debug_data(showing_debug_data);
   grid_render_component.render();

   if (state != STATE_ACTIVE) return;

   // draw a hilight box under the focused measure
   Measure::Base *measure = get_measure_at_cursor();

   Note *note = get_note_at_cursor();
   float CACHED_get_measure_cursor_real_x = get_measure_cursor_real_x();
   float CACHED_get_measure_cursor_real_y = get_measure_cursor_real_y();

   // draw the measure

   float measure_width = get_measure_width(measure) * FULL_MEASURE_WIDTH;
   if (measure && measure->get_num_notes() == 0)
   {
      measure_width = 16;

      // measure box outline
      if (is_measure_target_mode())
         al_draw_rounded_rectangle(CACHED_get_measure_cursor_real_x, GridHelper::get_height_to_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
            CACHED_get_measure_cursor_real_x+measure_width, GridHelper::get_height_to_staff(grid, measure_cursor_y)*STAFF_HEIGHT+GridHelper::get_height_of_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
            4, 4, color::color(color::black, 0.3), 2.0);
   }

   // measure box fill
   al_draw_filled_rounded_rectangle(CACHED_get_measure_cursor_real_x, GridHelper::get_height_to_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
      CACHED_get_measure_cursor_real_x+measure_width, GridHelper::get_height_to_staff(grid, measure_cursor_y)*STAFF_HEIGHT+GridHelper::get_height_of_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
      4, 4, color::color(color::aliceblue, 0.2));

   // measure box outline
   if (is_measure_target_mode())
      al_draw_rounded_rectangle(CACHED_get_measure_cursor_real_x, GridHelper::get_height_to_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
         CACHED_get_measure_cursor_real_x+measure_width, GridHelper::get_height_to_staff(grid, measure_cursor_y)*STAFF_HEIGHT+GridHelper::get_height_of_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
         4, 4, color::color(color::aliceblue, 0.7), 2.0);

   // left bar (blinking)

   ALLEGRO_COLOR cursor_color = color::color(color::white, sin(Framework::time_now*5) + 0.5);
   al_draw_line(CACHED_get_measure_cursor_real_x, CACHED_get_measure_cursor_real_y,
         CACHED_get_measure_cursor_real_x, CACHED_get_measure_cursor_real_y+GridHelper::get_height_of_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
         cursor_color, 3.0);

   // draw a hilight box at the focused note
   if (is_note_target_mode() && note)
   {
      float note_real_offset_x = get_measure_length_to_note(measure, note_cursor_x) * FULL_MEASURE_WIDTH;
      float real_note_width = DurationHelper::get_length(note->duration.denominator, note->duration.dots) * FULL_MEASURE_WIDTH;

      // note box fill
      al_draw_filled_rounded_rectangle(
            CACHED_get_measure_cursor_real_x + note_real_offset_x,
            CACHED_get_measure_cursor_real_y,
            CACHED_get_measure_cursor_real_x + note_real_offset_x + real_note_width,
            CACHED_get_measure_cursor_real_y + GridHelper::get_height_of_staff(grid, measure_cursor_y)*STAFF_HEIGHT,
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




void UIGridEditor::on_timer()
{
   playback_control.update(Framework::time_now);

   // match the width of the widget to the width of the score
   float grid_real_width = GridHelper::get_length_to_measure(grid, grid.get_num_measures()) * FULL_MEASURE_WIDTH;
   float grid_real_height = grid.get_num_staves() * STAFF_HEIGHT;

   place.size = vec2d(grid_real_width, grid_real_height);
}




Measure::Base *UIGridEditor::get_measure_at_cursor()
{
   return grid.get_measure(measure_cursor_x, measure_cursor_y);
}




Note *UIGridEditor::get_note_at_cursor()
{
   Measure::Base *focused_measure = get_measure_at_cursor();
   if (!focused_measure) return NULL;

   std::vector<Note> *notes = focused_measure->get_notes_pointer();
   if (!notes || note_cursor_x < 0 || note_cursor_x >= notes->size()) return nullptr;

   return &notes->at(note_cursor_x);
}




float UIGridEditor::get_measure_cursor_real_x()
{
   return GridHelper::get_length_to_measure(grid, measure_cursor_x) * FULL_MEASURE_WIDTH;
}




float UIGridEditor::get_measure_cursor_real_y()
{
   return GridHelper::get_height_to_staff(grid, measure_cursor_y) * STAFF_HEIGHT;
}




float UIGridEditor::get_measure_length_to_note(Measure::Base *measure, int note_index)
{
   float sum = 0;
   std::vector<Note> notes;
   if (measure) notes = measure->get_notes_copy();  // TODO: ineffecient use of get_notes_copy()

   if (note_index < 0 || note_index >= notes.size()) return 0;

   for (int i=0; i<note_index; i++)
      sum += DurationHelper::get_length(notes[i].duration.denominator, notes[i].duration.dots);
   return sum;
}




float UIGridEditor::get_measure_width(Measure::Base *m)  // TODO: should probably use a helper
{
   if (!m) return 0;
   float sum = 0;
   for (auto &note : m->get_notes_copy())  // TODO: ineffecient use of get_notes_copy()
      sum += DurationHelper::get_length(note.duration.denominator, note.duration.dots);
   return sum;
}




int UIGridEditor::move_measure_cursor_x(int delta)
{
   int num_measures = grid.get_num_measures();
   measure_cursor_x = limit<int>(0, num_measures-1, measure_cursor_x + delta);
   return measure_cursor_x;
}




int UIGridEditor::move_measure_cursor_y(int delta)
{
   int num_staves = grid.get_num_staves();
   measure_cursor_y = limit<int>(0, num_staves-1, measure_cursor_y + delta);
   return measure_cursor_y;
}




int UIGridEditor::move_note_cursor_x(int delta)
{
   Measure::Base *current_measure = grid.get_measure(measure_cursor_x, measure_cursor_y);
   if (!current_measure)
   {
      note_cursor_x = 0;
   }
   else
   {
      int num_notes = current_measure->get_notes_copy().size();  // TODO: ineffecient use of get_notes_copy()
      note_cursor_x = limit<int>(0, num_notes-1, note_cursor_x + delta);
   }
   return note_cursor_x;
}



void UIGridEditor::toggle_edit_mode_target()
{
   if (edit_mode_target == NOTE_TARGET) edit_mode_target = MEASURE_TARGET;
   else if (edit_mode_target == MEASURE_TARGET) edit_mode_target = NOTE_TARGET;
}




bool UIGridEditor::is_measure_target_mode()
{
   return edit_mode_target == MEASURE_TARGET;
}




bool UIGridEditor::is_note_target_mode()
{
   return edit_mode_target == NOTE_TARGET;
}




void UIGridEditor::set_state(state_t new_state)
{
   if (new_state == state) return;

   state = new_state;
}




