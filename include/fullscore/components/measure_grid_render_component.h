#pragma once




class MeasureGrid;

class MeasureGridRenderComponent
{
private:
   MeasureGrid *measure_grid;

public:
   MeasureGridRenderComponent(MeasureGrid *measure_grid);
   ~MeasureGridRenderComponent();

   void render();
};




