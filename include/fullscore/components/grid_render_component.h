#pragma once




class MeasureGrid;
class MusicEngraver;
class ReferenceCursor;

class MeasureGridRenderComponent
{
private:
   MeasureGrid *grid;
   MusicEngraver *music_engraver;
   ReferenceCursor *reference_cursor;
   float full_measure_width;
   float staff_height;
   bool showing_debug_data;

public:
   MeasureGridRenderComponent(MeasureGrid *grid, MusicEngraver *engraver, ReferenceCursor *reference_cursor, float full_measure_width, float staff_height);
   ~MeasureGridRenderComponent();

   void set_showing_debug_data(bool show);

   void render();
};




