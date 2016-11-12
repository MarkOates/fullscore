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

public:
   MeasureGridRenderComponent(MeasureGrid *measure_grid, MusicEngraver *engraver, float full_measure_width, float staff_height);
   ~MeasureGridRenderComponent();

   void render();
};




