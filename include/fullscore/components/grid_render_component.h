#pragma once



class Grid;
class MusicEngraver;

class GridRenderComponent
{
private:
   Grid *grid;
   MusicEngraver *music_engraver;
   float full_measure_width;
   float staff_height;
   bool showing_debug_data;
   int focused_floating_measure_id;

public:
   GridRenderComponent(Grid *grid, MusicEngraver *engraver, float full_measure_width, float staff_height, int focused_floating_measure_id);
   ~GridRenderComponent();

   void set_showing_debug_data(bool show);

   void render();
};



