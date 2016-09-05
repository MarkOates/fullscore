



#include <fullscore/gui_score_editor.h>

#include <allegro_flare/allegro_flare.h>

#include <fullscore/transforms/double_duration_transform.h>
#include <fullscore/transforms/half_duration_transform.h>
#include <fullscore/transforms/invert_transform.h>
#include <fullscore/transforms/retrograde_transform.h>
#include <fullscore/transforms/transpose_transform.h>
#include <fullscore/transforms/toggle_rest_transform.h>


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
   , MEASURE_WIDTH(music_engraver.music_notation.get_quarter_note_spacing()*4)
   , input_mode(false)
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

   measure_grid.get_measure(2,1)->notes.push_back(Note(0));
   measure_grid.get_measure(2,1)->notes.push_back(Note(0));
   measure_grid.get_measure(2,1)->notes.push_back(Note(-1));
   measure_grid.get_measure(2,1)->notes.push_back(Note(-1));
   measure_grid.get_measure(3,1)->notes.push_back(Note(-2));
   measure_grid.get_measure(3,1)->notes.push_back(Note(-2));
   measure_grid.get_measure(3,1)->notes.push_back(Note(-3, 2));
}




void GUIScoreEditor::on_draw()
{
   // draw a background for the score
   al_draw_filled_rectangle(-30, -30,
      MEASURE_WIDTH * measure_grid.get_num_measures() + 30, STAFF_HEIGHT * measure_grid.get_num_staves() + 30,
      color::color(color::blanchedalmond, 0.2));

   // draw barlines
   for (int x=0; x<measure_grid.get_num_measures(); x++)
   {
      Measure *measure = measure_grid.get_measure(x, 0);
      al_draw_line(x * MEASURE_WIDTH, 0, x * MEASURE_WIDTH, STAFF_HEIGHT * measure_grid.get_num_staves(), color::color(color::black, 0.2), 1.0);
   }

   // draw a box under the focused measure
   if (is_measure_mode())
      if (get_hovered_measure())
         al_draw_filled_rounded_rectangle(measure_cursor_x*MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT, 
            measure_cursor_x*MEASURE_WIDTH+MEASURE_WIDTH, measure_cursor_y*STAFF_HEIGHT+STAFF_HEIGHT,
            4, 4, color::color(color::aliceblue, 0.2));

   // draw the notes and measures
   Note *hovered_note = get_hovered_note();

   for (int y=0; y<measure_grid.get_num_staves(); y++)
      for (int x=0; x<measure_grid.get_num_measures(); x++)
      {
         Measure *measure = measure_grid.get_measure(x,y);
         music_engraver.draw(measure, x*MEASURE_WIDTH, y*STAFF_HEIGHT + STAFF_HEIGHT/2, MEASURE_WIDTH);

         // draw the notes
         float x_cursor = 0;
         for (unsigned i=0; i<measure->notes.size(); i++)
         {
            int xx = x * MEASURE_WIDTH;
            int yy = y * STAFF_HEIGHT;
            Note &note = measure->notes[i];
            float width = note.get_duration_width() * MEASURE_WIDTH;

            // draw a hilight box under the focused note
            if (is_note_mode() && (&note == hovered_note))
               al_draw_filled_rounded_rectangle(xx+x_cursor, yy, xx+x_cursor+width, yy+STAFF_HEIGHT,
                     3, 3, color::color(color::pink, (&note==hovered_note) ? 0.4 : 0.2));

            // draw some debug info on the note
            if (showing_debug_data)
            {
               ALLEGRO_FONT *text_font = Framework::font("DroidSans.ttf 20");
               al_draw_text(text_font, color::white, xx+x_cursor, yy, 0, tostring(note.scale_degree).c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+20, 0, (tostring(note.duration) + "(" + tostring(note.dots) + ")").c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+40, 0, tostring(note.start_time).c_str());
               al_draw_text(text_font, color::white, xx+x_cursor, yy+60, 0, tostring(note.end_time).c_str());
            }

            x_cursor += width;
         }
      }

   // draw the playhead
   float playhead_x = playback_control.position * MEASURE_WIDTH;
   al_draw_line(playhead_x, -40, playhead_x, STAFF_HEIGHT * measure_grid.get_num_staves() + 40, color::color(color::lightcyan, 0.5), 3);
   al_draw_filled_triangle(playhead_x-8, -48, playhead_x+8, -48, playhead_x, -40+6, color::lightcyan);
   al_draw_filled_rectangle(playhead_x-8, -48-14, playhead_x+8, -48, color::lightcyan);

   // draw the measure cursor
   if (measure_cursor_x >= 0 && measure_cursor_y >= 0)
   {
      float measure_cursor_real_x = get_measure_cursor_real_x();
      float measure_cursor_real_y = get_measure_cursor_real_y();
      al_draw_line(measure_cursor_real_x, measure_cursor_real_y,
            measure_cursor_real_x, measure_cursor_real_y+STAFF_HEIGHT,
            color::white, 3.0);
   }
}




void GUIScoreEditor::on_timer()
{
   UIWidget::on_timer();

   playback_control.update(Framework::time_now);
}




Measure *GUIScoreEditor::get_hovered_measure()
{
   if (!UIWidget::focused) return NULL;

   return measure_grid.get_measure(measure_cursor_x, measure_cursor_y);
}




Note *GUIScoreEditor::get_hovered_note()
{
   Measure *focused_measure = get_hovered_measure();
   if (!focused_measure) return NULL;

   return focused_measure->get_note_at(note_cursor_x);
}




int GUIScoreEditor::get_hovered_measure_index()
{
   // this function relies on the fact that measure_cursor_x is bounds checked
   // is correctly used.  I think relying on measure_cursor_x to be these things
   // is actually a good design idea.
   return measure_cursor_x; // will be -1 if out of bounds
}




int GUIScoreEditor::get_hovered_staff_index()
{
   // (see comment in get_hovered_measure_index())
   return measure_cursor_y;
}




void GUIScoreEditor::on_key_down()
{
   if (!UIWidget::focused) return;

   std::vector<Note> *notes = nullptr;
   Note *note = nullptr;
   Transform::Base *transform = nullptr;

   // find the note/notes to transform
   if (is_measure_mode())
   {
      Measure *focused_measure = get_hovered_measure();
      if (focused_measure) notes = &focused_measure->notes;
   }
   else
   {
      Note *focused_note = get_hovered_note();
      if (focused_note) note = focused_note;
   }

   // locate and build the appropriate transform
   switch(Framework::current_event->keyboard.keycode)
   {
   case ALLEGRO_KEY_W:
      // transpose up
      {
         // create the transformation
         Transform::Transpose transpose_transform(0);

         // find the amount of the transformation
         if (Framework::key_shift) transpose_transform.transposition = 7;
         else if (Framework::key_ctrl); // nothing (this add flats to the whole measure? .. probably not a feature to have)
         else transpose_transform.transposition = 1;

         // assign the transformation
         transform = &transpose_transform;
      }
      break;
   case ALLEGRO_KEY_S:
      // transpose down
      {
         // create the transformation
         Transform::Transpose transpose_transform(0);

         // find the amount of the transformation
         if (Framework::key_shift) transpose_transform.transposition = -7;
         else if (Framework::key_ctrl); // nothing (this add sharps to the whole measure? .. probably not a feature to have)
         else transpose_transform.transposition = -1;

         // assign the transformation
         transform = &transpose_transform;
      }
      break;
   case ALLEGRO_KEY_A:
      {
         Transform::HalfDuration half_duration_transform;
         transform = &half_duration_transform;
      }
      break;
   case ALLEGRO_KEY_D:
      {
         Transform::DoubleDuration double_duration_transform;
         transform = &double_duration_transform;
      }
      break;
   case ALLEGRO_KEY_R:
      {
         Transform::ToggleRest toggle_rest_transform;
         transform = &toggle_rest_transform;
      }
      break;
   case ALLEGRO_KEY_E:
      // erase the focused note
      {
         Measure *focused_measure = get_hovered_measure();
         if (!focused_measure) break;

         Note *focused_note = get_hovered_note();
         if (!focused_note) break;

         for (unsigned i=0; i<focused_measure->notes.size(); i++)
            if (&focused_measure->notes[i]==focused_note)
            {
               delete focused_note;
               focused_measure->notes.erase(focused_measure->notes.begin() + i);
               i--;
            }
      }
      break;
   case ALLEGRO_KEY_I:
      // invert the measure
      {
         Transform::Invert invert_transform(0);
         transform = &invert_transform;
      }
      break;
   case ALLEGRO_KEY_P:
      // retrograde the measure
      {
         Transform::Retrograde retrograde_transform;
         transform = &retrograde_transform;
      }
      break;
   case ALLEGRO_KEY_FULLSTOP:
      // add a dot
      {
         Note *focused_note = get_hovered_note();
         if (!focused_note) break;
         focused_note->dots = std::min(2, focused_note->dots+1);
      }
      break;
   case ALLEGRO_KEY_COMMA:
      // remove a dot
      {
         Note *focused_note = get_hovered_note();
         if (!focused_note) break;
         focused_note->dots = std::max(0, focused_note->dots-1);
      }
      break;

   case ALLEGRO_KEY_N:
      {
         // append a staff
         measure_grid.push_staff();
      }
      break;
   case ALLEGRO_KEY_M:
      {
         // append a measure
         measure_grid.push_measure();
      }
      break;
   default:
      break;
   }

   // perform the actual transformation
   if (transform)
   {
      if (note) *note = transform->transform({*note})[0];
      else if (notes) *notes = transform->transform(*notes);
   }
}




float GUIScoreEditor::get_measure_cursor_real_x()
{
   return measure_cursor_x * MEASURE_WIDTH;
}




float GUIScoreEditor::get_measure_cursor_real_y()
{
   return measure_cursor_y * STAFF_HEIGHT;
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




void GUIScoreEditor::toggle_input_mode()
{
   input_mode = !input_mode;
}




bool GUIScoreEditor::is_measure_mode()
{
   return input_mode;
}




bool GUIScoreEditor::is_note_mode()
{
   return !input_mode;
}




