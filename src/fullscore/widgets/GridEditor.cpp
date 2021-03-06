



#include <fullscore/widgets/GridEditor.h>

#include <allegro_flare/allegro_flare.h>

#include <fullscore/components/TimeSignatureRenderComponent.h>
#include <fullscore/components/UiGridEditorRenderComponent.h>
#include <fullscore/components/GridRenderComponent.h>
#include <fullscore/models/FloatingMeasure.h>
#include <fullscore/helpers/DurationHelper.h>
#include <fullscore/helpers/GridDimensionsHelper.h>
#include <cmath>




UIGridEditor::UIGridEditor(UIWidget *parent)
   // the widget is placed in the center of the screen with a padding of 10 pixels to the x and y edges
   : UIWidget(parent, "UIGridEditor", new UISurfaceAreaBoxPadded(0, 0, 300, 200, 30, 30, 30, 30))
   , grid()
   , playback_control()
   , grid_cursor_x(0)
   , grid_cursor_y(0)
   , note_cursor_x(0)
   , floating_measure_cursor()
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
   int floating_measure_id = floating_measure_cursor.get_floating_measure_id();
   FloatingMeasure *floating_measure = FloatingMeasure::find(floating_measure_id);
   if (!floating_measure) return nullptr;
   return Measure::find(floating_measure->get_measure_id());
}




Note *UIGridEditor::get_note_at_cursor()
{
   Measure::Base *focused_measure = get_measure_at_cursor();
   if (!focused_measure) return NULL;

   std::vector<Note> *notes = focused_measure->get_notes_pointer();
   if (!notes || note_cursor_x < 0 || note_cursor_x >= notes->size()) return nullptr;

   return &notes->at(note_cursor_x);
}




float UIGridEditor::get_grid_cursor_real_x()
{
   return GridDimensionsHelper::get_length_to_measure(grid, grid_cursor_x) * FULL_MEASURE_WIDTH;
}




float UIGridEditor::get_grid_cursor_real_y()
{
   return GridDimensionsHelper::get_height_to_staff(grid, grid_cursor_y) * STAFF_HEIGHT;
}




float UIGridEditor::get_measure_width(Measure::Base *m)  // TODO: should probably use a helper
{
   if (!m) return 0;
   float sum = 0;
   for (auto &note : m->get_notes_copy())  // TODO: ineffecient use of get_notes_copy()
      sum += DurationHelper::get_length(note.get_duration());
   return sum;
}




int UIGridEditor::move_grid_cursor_x(int delta)
{
   int num_barlines = grid.get_num_barlines();
   grid_cursor_x = limit<int>(0, num_barlines-1, grid_cursor_x + delta);
   return grid_cursor_x;
}




int UIGridEditor::move_grid_cursor_y(int delta)
{
   int num_staves = grid.get_num_staves();
   grid_cursor_y = limit<int>(0, num_staves-1, grid_cursor_y + delta);
   return grid_cursor_y;
}




int UIGridEditor::move_note_cursor_x(int delta)
{
   Measure::Base *current_measure = get_measure_at_cursor();
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




