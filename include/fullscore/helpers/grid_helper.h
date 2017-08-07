#pragma once




class Grid;

class GridHelper
{
public:
   static float get_length_to_measure(const Grid &grid, int measure_index);
   static float get_height_to_staff(const Grid &grid, int staff_index);
   static float get_height_of_staff(Grid &grid, int staff_index);
   static float get_width(const Grid &grid);
};




