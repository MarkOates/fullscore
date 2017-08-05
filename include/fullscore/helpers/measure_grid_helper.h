#pragma once




class MeasureGrid;

class MeasureGridHelper
{
public:
   static float get_length_to_measure(const MeasureGrid &measure_grid, int measure_index);
   static float get_height_to_staff(const MeasureGrid &measure_grid, int staff_index);
   static float get_height_of_staff(MeasureGrid &measure_grid, int staff_index);
   static float get_width(const MeasureGrid &measure_grid);
};




