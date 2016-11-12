#pragma once




class MeasureGrid;

class MeasureGridRenderComponent
{
private:
   MeasureGrid *measure_grid;
   float full_measure_width;
   float staff_height;

public:
   MeasureGridRenderComponent(MeasureGrid *measure_grid, float full_measure_width, float staff_height);
   ~MeasureGridRenderComponent();

   void render();
};




