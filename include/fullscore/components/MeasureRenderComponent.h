#pragma once



namespace Measure { class Base; }
class MusicEngraver;



class MeasureRenderComponent
{
private:
   Measure::Base *context;
   Measure::Base *measure;
   MusicEngraver *music_engraver;
   float full_measure_width;
   float x_pos;
   float y_pos;
   float row_middle_y;
   float staff_height;
   bool showing_debug_data;
   bool is_focused;
   bool in_edit_mode;
   int note_cursor_pos;

public:
   MeasureRenderComponent(Measure::Base *context, Measure::Base *measure, MusicEngraver *music_engraver, float full_measure_width, float x_pos, float y_pos, float row_middle_y, float staff_height, bool showing_debug_data, bool is_focused, bool in_edit_mode, int note_cursor_pos);

   void render();
};



