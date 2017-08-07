#pragma once



class Grid;



class ReferenceCursor
{
private:
   Grid *grid;
   int x;
   int y;

public:
   ReferenceCursor();
   ReferenceCursor(Grid *grid, int x, int y);

   void set_position(Grid *grid, int x, int y);
   int get_x();
   int get_y();
   Grid *get_grid();
   void set_coordinates(int x, int y);
   bool is_on_grid(const Grid *grid);
   void move(int delta_x, int delta_y);
   bool is_valid();
};



