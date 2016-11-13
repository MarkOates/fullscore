#pragma once




class MeasureGrid;
class MusicEngraver;

class MeasureGridRenderComponent
{
private:
   MeasureGrid *measure_grid;
   MusicEngraver *music_engraver;
   float full_measure_width;
   float staff_height;
   bool showing_debug_data;

public:
   MeasureGridRenderComponent(MeasureGrid *measure_grid, MusicEngraver *engraver, float full_measure_width, float staff_height);
   ~MeasureGridRenderComponent();

   void set_showing_debug_data(bool show);

   void render();
};




