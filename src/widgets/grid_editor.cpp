



#include <fullscore/widgets/grid_editor.h>

#include <allegro_flare/allegro_flare.h>

#include <fullscore/components/time_signature_render_component.h>
#include <fullscore/components/ui_grid_editor_render_component.h>
#include <fullscore/components/grid_render_component.h>
#include <fullscore/helpers/duration_helper.h>
#include <fullscore/helpers/grid_dimensions_helper.h>
#include <cmath>




UIGridEditor::UIGridEditor(UIWidget *parent)
   // the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
   : UIWidget(parent, "UIGridEditor", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
   , grid()
   , playback_control()
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
   UIGridEditorRenderComponent ui_grid_editor_render_component(*this);
   ui_grid_editor_render_component.render();
}




void UIGridEditor::on_timer()
{
   playback_control.update(Framework::time_now);

   // match the width of the widget to the width of the score
   float grid_real_width = GridDimensionsHelper::get_length_to_measure(grid, grid.get_num_barlines()) * FULL_MEASURE_WIDTH;
   float grid_real_height = grid.get_num_staves() * STAFF_HEIGHT;

   place.size = vec2d(grid_real_width, grid_real_height);
}




Measure::Base *UIGridEditor::get_measure_at_cursor()
{
   // this is the next milestone
   //throw std::runtime_error("UIGridEditor::get_measure_at_cursor() has been disabled");
   std::cout << "UIGridEditor::get_measure_at_cursor() has been disabled";
   return nullptr;
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
   return GridDimensionsHelper::get_length_to_measure(grid, measure_cursor_x) * FULL_MEASURE_WIDTH;
}




float UIGridEditor::get_measure_cursor_real_y()
{
   return GridDimensionsHelper::get_height_to_staff(grid, measure_cursor_y) * STAFF_HEIGHT;
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
   int num_barlines = grid.get_num_barlines();
   measure_cursor_x = limit<int>(0, num_barlines-1, measure_cursor_x + delta);
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
   throw std::runtime_error("UIGridEditor::move_note_cursor_x has been disabled");
   Measure::Base *current_measure = nullptr;
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




