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

public:
   MeasureRenderComponent(Measure::Base *context, Measure::Base *measure, MusicEngraver *music_engraver, float full_measure_width, float x_pos, float y_pos, float row_middle_y, float staff_height, bool showing_debug_data, bool is_focused);

   void render();
};



