

#include <fullscore/UI/MeasureEditor/Widget.hpp>

#include <fullscore/UI/MeasureEditor/Actions.hpp>
#include <fullscore/UI/MeasureEditor/RenderComponents/Measure.hpp>
#include <allegro_flare/allegro_flare.h>
#include <fullscore/models/measures/Base.h>


namespace UI::MeasureEditor
{


Widget::Widget(UIWidget *parent, Measure::Basic *measure)
   : UIWidget(parent, "MeasureEditor", new UISurfaceAreaBox(0, 0, 300, 200))
   , measure(measure)
   , note_mode_keyboard_commands()
   , measure_mode_keyboard_commands()
   , note_cursor_x(0)
   , edit_mode_target(MEASURE_TARGET)
   , mode(NORMAL_MODE)
   , music_engraver()
   , STAFF_HEIGHT(80)
   , FULL_MEASURE_WIDTH(music_engraver.music_notation.get_quarter_note_spacing()*4)
{
}


Note *Widget::get_note_at_cursor()
{
   Measure::Base *focused_measure = get_measure();
   if (!focused_measure) return NULL;

   std::vector<Note> *notes = focused_measure->get_notes_pointer();
   if (!notes || note_cursor_x < 0 || note_cursor_x >= notes->size()) return nullptr;

   return &notes->at(note_cursor_x);
}


int Widget::move_note_cursor_x(int delta)
{
   Measure::Base *current_measure = get_measure();
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


bool Widget::is_measure_target_mode()
{
   return edit_mode_target == MEASURE_TARGET;
}


bool Widget::is_note_target_mode()
{
   return edit_mode_target == NOTE_TARGET;
}


void Widget::toggle_edit_mode_target()
{
   if (edit_mode_target == NOTE_TARGET) edit_mode_target = MEASURE_TARGET;
   else if (edit_mode_target == MEASURE_TARGET) edit_mode_target = NOTE_TARGET;
}


Measure::Base *Widget::get_measure()
{
   return measure;
}


std::vector<std::string> Widget::get_keyboard_action_mapping(int al_keycode, bool shift, bool ctrl, bool alt)
{
   switch(edit_mode_target)
   {
   case MEASURE_TARGET:
      return measure_mode_keyboard_commands.get_mapping(al_keycode, shift, ctrl, alt);
      break;
   case NOTE_TARGET:
      return note_mode_keyboard_commands.get_mapping(al_keycode, shift, ctrl, alt);
      break;
   default:
      break;
   }

   return {};
}


void Widget::on_draw()
{
   al_draw_filled_rectangle(0, 0, place.size.x, place.size.y, al_color_name("white"));
   // this is the hacky measure for providing context-relative transformations when rendering
   // (but, we shouldn't be doing transformations inside the renderer, so there needs to be a different approach)
   static Measure::Basic *context_measure = new Measure::Basic({Note(0), Note(2), Note(4), Note(5), Note(7), Note(9), Note(11)});

   //for (auto &floating_measure : FloatingMeasure::find_at_staff_and_barline(staff->get_id(), x))
   //{
    //  float floating_measure_x_offset = floating_measure->get_grid_coordinate().get_grid_horizontal_coordinate().get_beat_coordinate().get_x_offset() * full_measure_width / 4.0;
     // bool is_focused = (focused_floating_measure_id == floating_measure->get_id());
      //Measure::Base *floating_measure_measure = Measure::find(floating_measure->get_measure_id(), Measure::FIND_OPTION_RAISE_NOT_FOUND);


      float x_pos = 0;
      float y_pos = 0;
      float row_middle_y = 90;
      float this_staff_height = STAFF_HEIGHT;
      float full_measure_width = FULL_MEASURE_WIDTH;
      bool showing_debug_data = false;
      bool is_focused = true;
      bool is_note_target = (edit_mode_target == NOTE_TARGET);

      RenderComponents::MeasureRenderComponent measure_render_component(context_measure, measure, &music_engraver, full_measure_width, x_pos, y_pos, row_middle_y, this_staff_height, showing_debug_data, is_focused, is_note_target, note_cursor_x);
      measure_render_component.render();
   //}
}


} // namespace UI::MeasureEditor


