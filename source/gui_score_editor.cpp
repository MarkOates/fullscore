



#include <fullscore/gui_score_editor.h>

#include <allegro_flare/allegro_flare.h>

#include <fullscore/components/time_signature_render_component.h>




const bool TEMPORARILY_DISABLE = false;


GUIScoreEditor::GUIScoreEditor(UIWidget *parent, Display *display, PlaybackDeviceInterface *playback_device)
   // the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
   : UIWidget(parent, "GUIScoreEditor",
      new UISurfaceAreaBox(display->center(), display->middle(), display->width()-20, display->height()-20))
   , measure_grid(8, 3)
   , playback_control(&measure_grid, playback_device)
   , measure_cursor_x(0)
   , measure_cursor_y(0)
   , note_cursor_x(0)
   , music_engraver()
   , showing_debug_data(false)
   , STAFF_HEIGHT(80)
   , FULL_MEASURE_WIDTH(music_engraver.music_notation.get_quarter_note_spacing()*4)
   , edit_mode_target(MEASURE_TARGET)
   , mode(NORMAL_MODE)
{
   attr.set(UI_ATTR__UI_WIDGET_TYPE, "UIScoreEditor");
   attr.set("id", "UIScoreEditor" + tostring(UIWidget::get_num_created_widgets()));

   // twinkle twinkle, little star
   measure_grid.get_measure(0,0)->notes.push_back(Note(0));
   measure_grid.get_measure(0,0)->notes.push_back(Note(0));
   measure_grid.get_measure(0,0)->notes.push_back(Note(4));
   measure_grid.get_measure(0,0)->notes.push_back(Note(4));
   measure_grid.get_measure(1,0)->notes.push_back(Note(5));
   measure_grid.get_measure(1,0)->notes.push_back(Note(5));
   measure_grid.get_measure(1,0)->notes.push_back(Note(4, 2));

   measure_grid.get_measure(2,0)->notes.push_back(Note(0+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(0+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(-1+3));
   measure_grid.get_measure(2,0)->notes.push_back(Note(-1+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-2+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-2+3));
   measure_grid.get_measure(3,0)->notes.push_back(Note(-3+3, 2));

   // test time signatures
   measure_grid.set_time_signature(2, TimeSignature(3, 4));
   measure_grid.set_time_signature(5, TimeSignature(5, 8));
}




void GUIScoreEditor::on_draw()
{
   // draw a background for the score
   al_draw_filled_rectangle(-30, -30,
      FULL_MEASURE_WIDTH * measure_grid.get_num_measures() + 30, STAFF_HEIGHT * measure_grid.get_num_staves() + 30,
      color::color(color::blanchedalmond, 0.2));

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
            float width = note.get_duration_width() * FULL_MEASURE_WIDTH;

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
      float note_width = note->get_duration_width() * FULL_MEASURE_WIDTH;

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

   // draw the measure cursor
   if (measure_cursor_x >= 0 && measure_cursor_y >= 0)
   {
      float measure_cursor_real_x = get_measure_cursor_real_x();
      float measure_cursor_real_y = get_measure_cursor_real_y();
      al_draw_line(measure_cursor_real_x, measure_cursor_real_y,
            measure_cursor_real_x, measure_cursor_real_y+STAFF_HEIGHT,
            color::white, 3.0);
   }

   // draw the playhead
   float playhead_x = playback_control.position * FULL_MEASURE_WIDTH;
   al_draw_line(playhead_x, -40, playhead_x, STAFF_HEIGHT * measure_grid.get_num_staves() + 40, color::color(color::lightcyan, 0.5), 3);
   al_draw_filled_triangle(playhead_x-8, -48, playhead_x+8, -48, playhead_x, -40+6, color::lightcyan);
   al_draw_filled_rectangle(playhead_x-8, -48-14, playhead_x+8, -48, color::lightcyan);
}




void GUIScoreEditor::on_timer()
{
   UIWidget::on_timer();

   playback_control.update(Framework::time_now);
}




Measure *GUIScoreEditor::get_measure_at_cursor()
{
   return measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
}




Note *GUIScoreEditor::get_note_at_cursor()
{
   Measure *focused_measure = get_measure_at_cursor();
   if (!focused_measure) return NULL;

   return focused_measure->operator[](note_cursor_x);
}




float GUIScoreEditor::get_measure_cursor_real_x()
{
   return measure_cursor_x * FULL_MEASURE_WIDTH;
}




float GUIScoreEditor::get_measure_cursor_real_y()
{
   return measure_cursor_y * STAFF_HEIGHT;
}




float GUIScoreEditor::get_measure_length_to_note(Measure &measure, int note_index)
{
   float sum = 0;
   if (note_index < 0 || note_index >= measure.notes.size()) return 0;

   for (int i=0; i<note_index; i++)
      sum += measure.notes[i].get_duration_width();
   return sum;
}




float GUIScoreEditor::get_measure_width(Measure &m)
{
   float sum = 0;
   for (auto &note : m.notes) sum += note.get_duration_width();
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
   Measure *current_measure = measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
   if (!current_measure)
   {
      note_cursor_x = 0;
   }
   else
   {
      int num_notes = current_measure->notes.size();
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



