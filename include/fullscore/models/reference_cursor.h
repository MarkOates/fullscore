#pragma once



class MeasureGrid;



class ReferenceCursor
{
private:
   MeasureGrid *measure_grid;
   int x;
   int y;

public:
   ReferenceCursor();
   ReferenceCursor(MeasureGrid *measure_grid, int x, int y);

   void set_position(MeasureGrid *measure_grid, int x, int y);
   int get_x();
   int get_y();
   MeasureGrid *get_measure_grid();
   void set_coordinates(int x, int y);
   bool is_on_measure_grid(const MeasureGrid *measure_grid);
   void move(int delta_x, int delta_y);
   bool is_valid();
};



