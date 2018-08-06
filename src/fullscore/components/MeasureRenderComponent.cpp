


#include <fullscore/components/MeasureRenderComponent.h>

#include <allegro_flare/framework.h>
#include <allegro_flare/color.h>
#include <allegro_flare/useful_php.h>
#include <fullscore/helpers/DurationHelper.h>
#include <fullscore/models/Measure.h>
#include <fullscore/renderers/MeasureSelectionBoxRenderer.h>
#include <fullscore/services/MusicEngraver.h>
#include <utility>



static float __get_measure_width(Measure::Base *m)  // TODO: should probably use a helper
{
   if (!m) return 0;
   float sum = 0;
   for (auto &note : m->get_notes_copy())  // TODO: ineffecient use of get_notes_copy()
      sum += DurationHelper::get_length(note.get_duration());
   return sum;
}



static float __get_measure_length_to_note(Measure::Base *measure, int note_index)
{
   float sum = 0;
   std::vector<Note> notes;
   if (measure) notes = measure->get_notes_copy();  // TODO: ineffecient use of get_notes_copy()

   if (note_index < 0 || note_index >= notes.size()) return 0;

   for (int i=0; i<note_index; i++)
      sum += DurationHelper::get_length(notes[i].get_duration());
   return sum;
}




static std::tuple<std::string, std::string> __get_context_pitch_and_extension(Measure::Base *context, Note *note)
{
   if (!context && !note) return std::tuple<std::string, std::string>("E", "E");

   std::vector<Note> notes = context->get_notes_copy();
   if (notes.empty()) return std::tuple<std::string, std::string>("=", "=");

   int offset = 128;
   int scale_degree = note->get_pitch().get_scale_degree();

   int context_pitch = notes[(scale_degree+offset*(int)notes.size()) % (int)notes.size()].get_pitch().get_scale_degree();
   int context_extension = ((int)note->get_pitch().get_scale_degree() + offset * (int)notes.size()) / (int)notes.size() - offset;

   return std::tuple<std::string, std::string>(tostring(context_pitch), tostring(context_extension));
}



MeasureRenderComponent::MeasureRenderComponent(Measure::Base *context, Measure::Base *measure, MusicEngraver *music_engraver, float full_measure_width, float x_pos, float y_pos, float row_middle_y, float staff_height, bool showing_debug_data, bool is_focused, bool in_edit_mode, int note_cursor_pos)
   : context(context)
   , measure(measure)
   , music_engraver(music_engraver)
   , full_measure_width(full_measure_width)
   , x_pos(x_pos)
   , y_pos(y_pos)
   , row_middle_y(row_middle_y)
   , staff_height(staff_height)
   , showing_debug_data(showing_debug_data)
   , is_focused(is_focused)
   , in_edit_mode(in_edit_mode)
   , note_cursor_pos(note_cursor_pos)
{}



void MeasureRenderComponent::render()
{
   ALLEGRO_COLOR measure_block_color = color::color(color::white, 0.2);
   ALLEGRO_COLOR notation_color = color::null_color;
   ALLEGRO_COLOR staff_line_color = color::null_color;

   int measure_width = 16;

   if (measure->get_num_notes() > 0)
      measure_width = __get_measure_width(measure) * full_measure_width;

   if (measure->is_type(Measure::TYPE_IDENTIFIER_REFERENCE_BY_ID))
   {
      measure_block_color = color::color(color::orange, 0.1);
   }
   else if (measure->is_type(Measure::TYPE_IDENTIFIER_STACK))
   {
      measure_block_color = color::color(color::red, 0.1);
   }
   else if (measure->is_type(Measure::TYPE_IDENTIFIER_STATIC))
   {
      measure_block_color = color::color(color::dodgerblue, 0.1);
   }
   else if (measure->is_type(Measure::TYPE_IDENTIFIER_BASIC))
   {
      measure_block_color = color::color(color::white, 0.075);
   }
   else if (measure->is_type(Measure::TYPE_IDENTIFIER_PLOTTED))
   {
      measure_block_color = color::color(color::aliceblue, 0.5);
      notation_color = color::blue;
      staff_line_color = color::blue;
   }

   // draw the music notes

   music_engraver->draw(measure, x_pos, y_pos + staff_height/2, full_measure_width, notation_color, staff_line_color);

   // draw the measure selection box

   MeasureSelectionBoxRenderer::state_t measure_selection_box_renderer_state = MeasureSelectionBoxRenderer::STATE_UNDEF;
   if (is_focused && in_edit_mode) measure_selection_box_renderer_state = MeasureSelectionBoxRenderer::STATE_NOTE_FOCUS;
   else if (is_focused) measure_selection_box_renderer_state = MeasureSelectionBoxRenderer::STATE_MEASURE_FOCUS;

   if (measure_selection_box_renderer_state != MeasureSelectionBoxRenderer::STATE_UNDEF)
   {
      std::vector<Note> *notes_in_measure = measure->get_notes_pointer();
      Note *note = nullptr;
      float real_note_width = 0;
      if (note_cursor_pos >= notes_in_measure->size() || note_cursor_pos < 0) {}
      else
      {
         note = &notes_in_measure->at(note_cursor_pos);
         real_note_width = DurationHelper::get_length(note->get_duration()) * full_measure_width;
      }

      float note_offset_x = __get_measure_length_to_note(measure, note_cursor_pos) * full_measure_width;

      MeasureSelectionBoxRenderer measure_selection_box_renderer(measure_selection_box_renderer_state, x_pos, y_pos, measure_width, staff_height, note_offset_x, real_note_width);
      measure_selection_box_renderer.render();
   }

   return;
}



