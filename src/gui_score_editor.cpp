



#include <fullscore/gui_score_editor.h>

#include <allegro_flare/allegro_flare.h>

#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/components/measure_grid_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/measure_grid_helper.h>




GUIScoreEditor::RenderingDependencies::RenderingDependencies(ReferenceCursor *reference_cursor)
   : reference_cursor(reference_cursor)
{}




void GUIScoreEditor::RenderingDependencies::set_reference_cursor(ReferenceCursor *reference_cursor)
{
   this->reference_cursor = reference_cursor;
}




GUIScoreEditor::GUIScoreEditor(UIWidget *parent, ReferenceCursor *reference_cursor)
   // the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
   : UIWidget(parent, "GUIScoreEditor", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
   , measure_grid(0, 0)
   , playback_control()
   , rendering_dependencies(reference_cursor)
   , measure_cursor_x(0)
   , measure_cursor_y(0)
   , note_cursor_x(0)
   , music_engraver()
   , showing_debug_data(false)
   , STAFF_HEIGHT(80)
   , FULL_MEASURE_WIDTH(music_engraver.music_notation.get_quarter_note_spacing()*4)
   , edit_mode_target(MEASURE_TARGET)
   , mode(NORMAL_MODE)
{}




void GUIScoreEditor::on_draw()
{
   // get_width_of_score
   float measure_grid_real_width = MeasureGridHelper::get_length_to_measure(measure_grid, measure_grid.get_num_measures()) * FULL_MEASURE_WIDTH;
   float measure_grid_real_height = measure_grid.get_num_staves() * STAFF_HEIGHT;

   // draw the bounding box for the widget
   float pt, pr, pb, pl;
   UISurfaceAreaBoxPadded *sa = static_cast<UISurfaceAreaBoxPadded *>(surface_area);
   sa->get_padding(&pt, &pr, &pb, &pl);
   al_draw_rounded_rectangle(-pl, -pt, place.size.x+pr, place.size.y+pb, 6, 6, color::color(color::black, state == STATE_ACTIVE ? 0.7 : 0.1), 2.0);

   if (state == STATE_ACTIVE)
   {
      // draw the inner-rectangle for the grid
      al_draw_filled_rectangle(0, 0, place.size.x, place.size.y, color::color(color::blanchedalmond, 0.2));

      // draw a background for the score
      al_draw_filled_rectangle(-30, -30,
         measure_grid_real_width + 30, measure_grid_real_height + 30,
         color::color(color::blanchedalmond, 0.2));
   }

   // render the measure grid
   MeasureGridRenderComponent measure_grid_render_component(&measure_grid, &music_engraver, rendering_dependencies.reference_cursor, FULL_MEASURE_WIDTH, STAFF_HEIGHT);
   measure_grid_render_component.set_showing_debug_data(showing_debug_data);
   measure_grid_render_component.render();

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
         al_draw_rounded_rectangle(CACHED_get_measure_cursor_real_x, measure_cursor_y*STAFF_HEIGHT,
            CACHED_get_measure_cursor_real_x+measure_width, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
            4, 4, color::color(color::black, 0.3), 2.0);
   }

   // measure box fill
   al_draw_filled_rounded_rectangle(CACHED_get_measure_cursor_real_x, measure_cursor_y*STAFF_HEIGHT,
      CACHED_get_measure_cursor_real_x+measure_width, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
      4, 4, color::color(color::aliceblue, 0.2));

   // measure box outline
   if (is_measure_target_mode())
      al_draw_rounded_rectangle(CACHED_get_measure_cursor_real_x, measure_cursor_y*STAFF_HEIGHT,
         CACHED_get_measure_cursor_real_x+measure_width, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
         4, 4, color::color(color::aliceblue, 0.7), 2.0);

   // left bar
   al_draw_line(CACHED_get_measure_cursor_real_x, CACHED_get_measure_cursor_real_y,
         CACHED_get_measure_cursor_real_x, CACHED_get_measure_cursor_real_y+STAFF_HEIGHT,
         color::white, 3.0);

   // draw a hilight box at the focused note
   if (note)
   {
      float note_real_offset_x = get_measure_length_to_note(measure, note_cursor_x) * FULL_MEASURE_WIDTH;
      float real_note_width = DurationHelper::get_length(note->duration.denominator, note->duration.dots) * FULL_MEASURE_WIDTH;

      // note box fill
      al_draw_filled_rounded_rectangle(
            CACHED_get_measure_cursor_real_x + note_real_offset_x,
            CACHED_get_measure_cursor_real_y,
            CACHED_get_measure_cursor_real_x + note_real_offset_x + real_note_width,
            CACHED_get_measure_cursor_real_y + STAFF_HEIGHT,
            6,
            6,
            color::color(color::pink, 0.4)
         );

      // note box outline
      if (is_note_target_mode())
         al_draw_rounded_rectangle(
               CACHED_get_measure_cursor_real_x + note_real_offset_x,
               CACHED_get_measure_cursor_real_y,
               CACHED_get_measure_cursor_real_x + note_real_offset_x + real_note_width,
               CACHED_get_measure_cursor_real_y + STAFF_HEIGHT,
               6,
               6,
               color::mix(color::color(color::pink, 0.8), color::black, 0.3),
               2.0
            );
   }

   // draw the playhead
   float playhead_x = playback_control.position * FULL_MEASURE_WIDTH;
   float playhead_y = -40;
   al_draw_line(playhead_x, playhead_y, playhead_x, measure_grid_real_height + 40, color::color(color::lightcyan, 0.5), 3);
   al_draw_filled_triangle(playhead_x-8, playhead_y-8, playhead_x+8, playhead_y-8, playhead_x, playhead_y+6, color::lightcyan);
   al_draw_filled_rectangle(playhead_x-8, playhead_y-8-14, playhead_x+8, playhead_y-8, color::lightcyan);
}




void GUIScoreEditor::on_timer()
{
   playback_control.update(Framework::time_now);

   // match the width of the widget to the width of the score
   float measure_grid_real_width = MeasureGridHelper::get_length_to_measure(measure_grid, measure_grid.get_num_measures()) * FULL_MEASURE_WIDTH;
   float measure_grid_real_height = measure_grid.get_num_staves() * STAFF_HEIGHT;

   place.size = vec2d(measure_grid_real_width, measure_grid_real_height);
}




Measure::Base *GUIScoreEditor::get_measure_at_cursor()
{
   return measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
}




Note *GUIScoreEditor::get_note_at_cursor()
{
   Measure::Base *focused_measure = get_measure_at_cursor();
   if (!focused_measure) return NULL;

   std::vector<Note> *notes = focused_measure->get_notes_pointer();
   if (!notes || note_cursor_x < 0 || note_cursor_x >= notes->size()) return nullptr;

   return &notes->at(note_cursor_x);
}




float GUIScoreEditor::get_measure_cursor_real_x()
{
   return MeasureGridHelper::get_length_to_measure(measure_grid, measure_cursor_x) * FULL_MEASURE_WIDTH;
}




float GUIScoreEditor::get_measure_cursor_real_y()
{
   return measure_cursor_y * STAFF_HEIGHT;
}




float GUIScoreEditor::get_measure_length_to_note(Measure::Base *measure, int note_index)
{
   float sum = 0;
   std::vector<Note> notes;
   if (measure) notes = measure->get_notes_copy();  // TODO: ineffecient use of get_notes_copy()

   if (note_index < 0 || note_index >= notes.size()) return 0;

   for (int i=0; i<note_index; i++)
      sum += DurationHelper::get_length(notes[i].duration.denominator, notes[i].duration.dots);
   return sum;
}




float GUIScoreEditor::get_measure_width(Measure::Base *m)  // TODO: should probably use a helper
{
   if (!m) return 0;
   float sum = 0;
   for (auto &note : m->get_notes_copy())  // TODO: ineffecient use of get_notes_copy()
      sum += DurationHelper::get_length(note.duration.denominator, note.duration.dots);
   return sum;
}




int GUIScoreEditor::move_measure_cursor_x(int delta)
{
   int num_measures = measure_grid.get_num_measures();
   measure_cursor_x = limit<int>(0, num_measures-1, measure_cursor_x + delta);
   return measure_cursor_x;
}




int GUIScoreEditor::move_measure_cursor_y(int delta)
{
   int num_staves = measure_grid.get_num_staves();
   measure_cursor_y = limit<int>(0, num_staves-1, measure_cursor_y + delta);
   return measure_cursor_y;
}




int GUIScoreEditor::move_note_cursor_x(int delta)
{
   Measure::Base *current_measure = measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
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



void GUIScoreEditor::toggle_edit_mode_target()
{
   if (edit_mode_target == NOTE_TARGET) edit_mode_target = MEASURE_TARGET;
   else if (edit_mode_target == MEASURE_TARGET) edit_mode_target = NOTE_TARGET;
}




bool GUIScoreEditor::is_measure_target_mode()
{
   return edit_mode_target == MEASURE_TARGET;
}




bool GUIScoreEditor::is_note_target_mode()
{
   return edit_mode_target == NOTE_TARGET;
}




void GUIScoreEditor::set_state(state_t new_state)
{
   if (new_state == state) return;

   state = new_state;
}




