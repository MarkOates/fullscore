#pragma once




class Grid;
class MusicEngraver;
class ReferenceCursor;

class GridRenderComponent
{
private:
   Grid *grid;
   MusicEngraver *music_engraver;
   ReferenceCursor *reference_cursor;
   float full_measure_width;
   float staff_height;
   bool showing_debug_data;

public:
   GridRenderComponent(Grid *grid, MusicEngraver *engraver, ReferenceCursor *reference_cursor, float full_measure_width, float staff_height);
   ~GridRenderComponent();

   void set_showing_debug_data(bool show);

   void render();
};




