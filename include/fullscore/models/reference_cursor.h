#pragma once



class MeasureGrid;



class ReferenceCursor
{
private:
   MeasureGrid *grid;
   int x;
   int y;

public:
   ReferenceCursor();
   ReferenceCursor(MeasureGrid *grid, int x, int y);

   void set_position(MeasureGrid *grid, int x, int y);
   int get_x();
   int get_y();
   MeasureGrid *get_grid();
   void set_coordinates(int x, int y);
   bool is_on_grid(const MeasureGrid *grid);
   void move(int delta_x, int delta_y);
   bool is_valid();
};



