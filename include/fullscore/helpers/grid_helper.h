#pragma once




class MeasureGrid;

class MeasureGridHelper
{
public:
   static float get_length_to_measure(const MeasureGrid &grid, int measure_index);
   static float get_height_to_staff(const MeasureGrid &grid, int staff_index);
   static float get_height_of_staff(MeasureGrid &grid, int staff_index);
   static float get_width(const MeasureGrid &grid);
};




